#include <LiquidCrystal.h>
#include "emojis.h"

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

class Pantallita {
  private:
    // LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

    String formula[CANT_FORMS];

    const int ritmoLento = 1500;
    const int ritmoRapido = 200;
    long tiempo;
    int cursorx;
    int randomChar;

  public:
    void initPin() {
      lcd.begin(16, 2);

      formula[0] = FORM_0;
      formula[1] = FORM_1;
      formula[2] = FORM_2;
      formula[3] = FORM_3;
      formula[4] = FORM_4;

      tiempo = ritmoLento;

      lcd.createChar(0, musicaA);
      lcd.createChar(1, musicaB);
      lcd.createChar(2, bigSmile);
      lcd.createChar(3, smiley);
      lcd.createChar(4, chill);
      lcd.createChar(5, neutralSmiley);
    }

    void entrarEnReposo() {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("   >>>>(.)<<<<  ");
      cursorx = 7;
    }
    void reposar() {
      if (millis() > tiempo) {
        tiempo += ritmoLento;
        lcd.setCursor(cursorx, 0);
        lcd.write('.');
        //cursorx = 7 + (((cursorx - 7) + 1) % 3);
        cursorx ++;
        if (cursorx >= 11) {
          entrarEnReposo();
        }
      }
    }

    void entrarEnBaile() {
      lcd.clear();
      lcd.setCursor(0, 0);
      for (int i = 0; i < 16; i++) lcd.print(char(round(random(48, 50))));
      cursorx = 0;
    }
    void bailar() {
      if (millis() > tiempo) {
        tiempo += ritmoLento;

        for (int i = 1; i < 15; i++){ 
          if (random(100) < 95) continue;
          lcd.setCursor(i, 0);
          lcd.write(byte(int(random(0,2))));
        }

        lcd.setCursor(7, 0);
        lcd.write(' ');
        lcd.write(byte(int(random(2,6))));
        lcd.write(' ');

        lcd.setCursor(0, 1);
        String str = formula[danceCount % CANT_FORMS];
        for (int i = 0; i < 16; i++) {
          lcd.print( str[ (i + cursorx) % str.length() ] );
        }
        cursorx = cursorx >= str.length() ? 0 : cursorx + 1;
      }
    }

    void gritar() {
      if (millis() > tiempo) {
        tiempo += ritmoRapido;

        lcd.setCursor(0, 0);
        escribirCaracteresRandom(0);

        lcd.setCursor(0, 1);
        escribirCaracteresRandom(1);
      }
    }
    void escribirCaracteresRandom(int col) {
      for (int i = 0; i < 17; i++) {
        if (random(100) < 50) continue;

        randomChar = errChars[int(random(ERR_CHARS_CANT))];
        lcd.write(randomChar);
        lcd.setCursor(i, col);
      }
    }
    
    void entrarEnCarga() {
      lcd.clear();
      lcd.setCursor(8,0);
      lcd.write(byte(5));
      lcd.setCursor(0,1);
      tiempo = millis() + cargaDuration/16;
    }
    void cargar() {
      if(millis() > tiempo){
        tiempo += cargaDuration/24;
        lcd.write('*');
      }
    }
};
