#include <Arduino.h>
#include <Servo.h>

class Servobo {
  private:
    Servo servo;
  public:
    // Constantes grito
    const long onFrequency = 200;
    const int onDuration = 50;
    const int amplitudGrito = 90;

    // Constantes Reposo
    const int velReposo = 0.01;

    float angulo = 0;

    void attach() {
      servo.attach(servoPin);
      servo.write(0);
    }

    void reposar() {
      angulo = ((cos(millis() * velReposo) * .5 + .5) * 180);
      servo.write(angulo);
    }

    void gritar() {
      angulo =  millis() % onFrequency < onDuration ?
                amplitudGrito :
                0;

      servo.write(angulo);
    }

    void bailar() {
      angulo = f(millis() * .1, danceCount % CANT_FORMS ) * 180;
      servo.write(angulo);
    }

    // MOVIMIENTO
    float f( float x, int id ) {
      x = radians(x);
      float y;

      switch (id) {
        case 0:
          y = sin(x + cos(x * atan(x * 1.5))) * .5 + .5; // Waves
          break;
        case 1:
          y = atan(max(cos(x * 2), sin(x * 2.15))) * .5 + .5; // Rebotecitos
          break;
        case 2:
          y = atan(cos(x + max(cos(x * 2), sin(x * 2.2)))) * .5 + .5; // Indecisión
          break;
        case 3:
          y = min(cos(round(sin(x * .5) * 3)), sin(x * 1.1)) * .5 + .5;
          break;
        case 4:
          y = min(max(abs(cos(x * 2)), abs(sin(x * 1.2))), cos(x * 1.1 + sin(x))) * .5 + .5; // No se si me caso
          break;
      }

      Serial.println(y);
      return y;
    }
};
