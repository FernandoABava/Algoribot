#include <Arduino.h>

class Lucecita {
  private:
  // float intensidad; TODO
  const long onFrequency = 100;
  const int onDuration = 50;
  
  public:  
  void initPin() {
    pinMode(ledPin, OUTPUT);  
  }

  void reposar() {
    digitalWrite(ledPin, LOW);  
  }  
  void titilar() {
    if (millis() % onFrequency < onDuration) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
  void bailar() {
    digitalWrite(ledPin, HIGH);
  }
};
