// #include <Arduino.h>

class Lucecita {
  private:
  // float intensidad; TODO
  const long onFrequency = 100;
  const int onDuration = 50;
  
  public:  
  void initPin() {
    pinMode(ledPin, OUTPUT);  
    pinMode(relePin, OUTPUT);  

    prenderRele();
  }

  void prenderLed() {
    digitalWrite(ledPin, HIGH);
  }

  void apagarLed() {
    digitalWrite(ledPin, LOW);
  }

  void prenderRele() {
    digitalWrite(relePin, HIGH);
  }

  void titilar() {
    if (millis() % onFrequency < onDuration) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }

  void prenderTodo() {
    digitalWrite(relePin, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  
  void apagarTodo() {
    digitalWrite(relePin, LOW);
    digitalWrite(ledPin, LOW);
  }
};
