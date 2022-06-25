
/* ***************
   *** ESTADOS ***
   *************** */
#define REPOSO 0
#define DANZA 1
#define HISTERIA 2

/* ****************
   *** FORMULAS ***
   **************** */
#define FORM_0 "sin(x+cos(x*atan(x*1.5)))"
#define FORM_1 "atan(max(cos(x*2),sin(x*2.15)))"
#define FORM_2 "atan(cos(x+max(cos(x*2),sin(x*2.2))))"
#define FORM_3 "min(cos(round(sin(x*.5)*3)),sin(x*1.1))"
#define FORM_4 "min(max(abs(cos(x*2)),abs(sin(x*1.2))),cos(x*1.1+sin(x)))"
#define CANT_FORMS 5

/* =============== */

/* PINES  ******
   *********** */
const int buttonPin = 2;
const int ledPin =  13;
const int servoPin = 11;
// pantallita
#define LCD_RS 8
#define LCD_EN 8
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

/* TIEMPO ******
   *********** */
const long histeriaDuration = 5000;

/*  VARIABLES **
 ************* */
int estado = 0;
int buttonState = 0;
long millisOfHisteria = histeriaDuration;
int danceCount = 0;
