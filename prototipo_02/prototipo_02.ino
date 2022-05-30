#include <Servo.h>
Servo servo;

// ESTADOS
const int REPOSO = 0;
const int DANZA = 1;
const int HISTERIA = 2;

// PINES
const int buttonPin = 2;
const int ledPin =  13;
const int servoPin = 9;

// CONSTANTES RITMO
const long histeriaDuration = 5000;
const long onFrequency = 100;
const int onDuration = 50;
const int factorTranquilidad = 6;

// variables will change:
int estado = 0;
int buttonState = 0;
long millisOfHisteria = histeriaDuration;
int danceCount = 0;

void setup() {
  Serial.begin(9600);
  // output:
  pinMode(ledPin, OUTPUT);
  // input:
  pinMode(buttonPin, INPUT);

  servo.attach(servoPin);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  danceCount = danceCount > 128 ? 0 : danceCount; // Clamp preventivo
  
  // CONDICIONES
  if (buttonState == HIGH) {
    if(estado == REPOSO || estado == HISTERIA) danceCount++;
    estado = DANZA;
  } else {
    if (millis() < millisOfHisteria) {
      estado = HISTERIA;
    } else {
      estado = REPOSO;
    }
  }

  // ESTADOS
  switch (estado) {
    case REPOSO:
      digitalWrite(ledPin, LOW);
      servo.write(0);
      break;
    case DANZA:
      millisOfHisteria = millis() + histeriaDuration;
      digitalWrite(ledPin, HIGH);

      //float a = f(millis() * .1, 0) * 180; NO DECLARAR VARIABLES EN UN SWITCH:CASE
      servo.write(f(millis() * .1, danceCount % 5 ) * 180);
         
      break;
    case HISTERIA:
      if (millis() % onFrequency < onDuration) {
        digitalWrite(ledPin, HIGH);
        servo.write(45);
      } else {
        digitalWrite(ledPin, LOW);
        servo.write(0);
      }
      break;
    default: break;
  }
}

float f( float x, int id ) {
  x = radians(x);
  float y;
  
  switch(id){
    case 0:
      y = sin(x + cos(x * atan(x * 1.5))) * .5 + .5; // Waves
      break;
    case 1:
      y = atan(max(cos(x* 2), sin(x * 2.15))) * .5 + .5; // Rebotecitos
      break;
    case 2:
      y = atan(cos(x + max(cos(x* 2), sin(x * 2.2)))) * .5 + .5; // Indecisión
      break;  
    case 3:
      y = min(cos(round(sin(x*.5)*3)), sin(x*1.1)) * .5 + .5;
      break;
    case 4: 
      y = min(max(abs(cos(x*2)), abs(sin(x*1.2))), cos(x*1.1 + sin(x))) *.5 + .5; // No se si me caso
      break;
  }

  // y = sin(x * cos(x * 1.1)) * .5 + .5; // Histeria (No loopeable)
  // y = sin(x + cos(x * atan(x * 1.5))) * .5 + .5; // Waves
  // y = atan(max(cos(x* 2), sin(x * 2.15))) * .5 + .5; // Rebotecitos
  // y = atan(cos(x + max(cos(x* 2), sin(x * 2.2)))) * .5 + .5; // Indecisión
  
  Serial.println(y);
  return y;
}
