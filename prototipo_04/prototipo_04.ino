#include <Servo.h>

#include "Globales.h";
#include "Servobo.h"
#include "Lucecita.h"
#include "Pantallita.h"

Servobo servobo;
Lucecita luz;
Pantallita pantallita;

void setup() {
  Serial.begin(9600);
  // output:
  pinMode(ledPin, OUTPUT);
  // input:
  pinMode(buttonPin, INPUT);

  servobo.attach();
  luz.initPin();
  pantallita.initPin();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  danceCount = danceCount > 128 ? 0 : danceCount; // Clamp preventivo
  
  // CONDICIONES
  if (buttonState == HIGH) {
    if(estado == REPOSO){
      estado = CARGA;
      triggerTime = millis() + cargaDuration;
      pantallita.entrarEnCarga();
    } else if((millis() > triggerTime && estado == CARGA) || estado == HISTERIA || estado == MUERTE){ 
      estado = DANZA;
      luz.prenderTodo();
      danceCount++;
      pantallita.entrarEnBaile();
    }
  } else {
    if (estado == DANZA) {      
      estado = HISTERIA;
    } else if(millis() > (triggerTime - muerteDuration) && estado == HISTERIA){
      estado = MUERTE;
      lcd.clear();
      luz.apagarTodo();
    } else if((millis() > triggerTime && estado == MUERTE) || estado == CARGA){
      estado = REPOSO;
      pantallita.entrarEnReposo();
      luz.prenderRele();
    }
  }

  // ESTADOS
  switch (estado) {
    case REPOSO:
      // triggerTime = millis() + cargaDuration;
      // luz.reposar();
      servobo.reposar();
      pantallita.reposar();
      break;
    case CARGA: 
      pantallita.cargar();
      luz.titilar();
      break;
    case DANZA:
      triggerTime = millis() + histeriaDuration + muerteDuration;
      // luz.bailar();
      servobo.bailar();
      pantallita.bailar();
      break;
    case HISTERIA:
      servobo.gritar();
      luz.titilar();
      pantallita.gritar();
      break;
    case MUERTE: 
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
