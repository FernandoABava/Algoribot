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

  // EVENTOS
  if (buttonState == HIGH) {
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
      
      if (millis() % (onFrequency * factorTranquilidad) < onDuration * factorTranquilidad) {
        servo.write(45);
      } else {
        servo.write(0);
      }
      f(millis() * .1);   
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

float f( float x ) {
  x = radians(x);
  float y;

  y = sin(x) * .5 + .5;
  
  Serial.println(y);
  return y;
}
