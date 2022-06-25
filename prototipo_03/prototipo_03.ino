#include <Servo.h>

#include "Globales.h";
#include "Servobo.h"
#include "Lucecitas.h"

Servobo servobo;
Lucecita luz;

void setup() {
  Serial.begin(9600);
  // output:
  pinMode(ledPin, OUTPUT);
  // input:
  pinMode(buttonPin, INPUT);

  servobo.attach();
  luz.initPin();
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
      luz.reposar();
      servobo.reposar();
      break;
    case DANZA:
      millisOfHisteria = millis() + histeriaDuration;
      luz.bailar();
      servobo.bailar();
         
      break;
    case HISTERIA:
      servobo.gritar();
      luz.titilar();
      break;
    default: break;
  }
}
/*
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
}*/

void writeOnScreen() {
  
}
