#include <Arduino.h>
#include <LiquidCrystal.h>

class Pantallita {
private:
  LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
  const String[] formula;

  const int ritmoLento = 1000;
  const int ritmoRapido = 200;
  long tiempo;
  int cursorx;
  int randomChar;
  
public:
  void initPin() {
    lcd.begin(16, 2);
    
    formula = new String[CANT_FORMS];
    formula[0] = FORM_0;
    formula[1] = FORM_1;
    formula[2] = FORM_2;
    formula[3] = FORM_3;
    formula[4] = FORM_4;

    tiempo = ritmoLento;
  }

  void entrarEnReposo() {
    lcd.clear();
    lcd.setCursor(0,1);  
    lcd.print("  >>>>(__)<<<<  ");
    cursorx = 7;
  }
  void reposar() {
    if(millis() > tiempo){
      tiempo += ritmoLento;
      lcd.setCursor(cursorx,0);
      lcd.write('.');
      //cursorx = 7 + (((cursorx - 7) + 1) % 3);
      cursorx ++;
      if(cursorx >= 10){
        entrarEnReposo();
      }
    }
  }
  
  void entrarEnBaile() {
    lcd.clear();
    lcd.setCursor(0,0);  
    for(int i=0; i<16; i++) lcd.print(char(round(random(48, 49))));
    cursorx = 0;
    lcd.setCursor(0,1);
  }
  void bailar() {
    if(millis() > tiempo){
      tiempo += ritmoLento;
      char str[] = formula[danceCount % CANT_FORMS];
      for(int i = 0; i<16; i++){
        lcd.print( str[ (i+cursorx) % formula.length() ] );
      }
      cursorx = cursorx >= formula.length() ? 0 : cursorx + 1;
    }
  }
  
  void gritar() {
    if(millis() > tiempo){
      tiempo += ritmoLento;
      
      lcd.setCursor(0,0);
      for(int i=0; i<errChars.length(); i++){
        randomChar = errChars[int(random(errChars.length()))];
        lcd.print(randomChar);
        lcd.setCursor(i,0);
      }
      
      lcd.setCursor(0,1);
      for(int i=0; i<errChars.length(); i++){
        randomChar = errChars[int(random(errChars.length()))];
        lcd.print(randomChar);
        lcd.setCursor(i,0);
      }
    }
  }
  // void cargar() {} TODO
};
