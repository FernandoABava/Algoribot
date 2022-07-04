
/* ***************
   *** ESTADOS ***
   *************** */
#define REPOSO 0
#define CARGA 1
#define DANZA 2
#define HISTERIA 3
#define MUERTE 4

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
#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

const int buttonPin = 2;
const int ledPin =  13;
const int relePin = 12;
const int servoPin = 11;

/* TIEMPO ******
   *********** */
const long histeriaDuration = 10000;
const long cargaDuration = 1500;
const long muerteDuration = 5000;

/* CHARS ******
   ********** */
#define ERR_CHARS_CANT 16
const char errChars[] = "###ERROR0**xx1!!";

/*  VARIABLES **
 ************* */
int estado = 0;
int buttonState = 0;
long triggerTime = 0;
int danceCount = 0;
