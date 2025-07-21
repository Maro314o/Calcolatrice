#include "_font.h"
#include "displaybuffer.h"
#include <math.h>
#define CHECK_ERROR_MACRO(error, error_buff) \
    do { \
        if (error) { \
            retrive_error(error_buff, error); \
            throw_error(error_buff); \
            return; \
        } \
    } while(0)

//display nokia
#define RST 20
#define CE 19
#define DC 18
#define DIN 17
#define CLK 16

#define NUMBERS 0
#define FUNCTION 1
#define COSTANT 2
#define MENU 3
#define LOG  104
#define ROOT 232
#define SIN  107
#define COS  108
#define TAN  109
#define LN  110
#define POW  111
#define X  20
#define E 21 
#define Pi 22 
#define SCIENTIFIC_CALCULATOR 0
#define GRAPHIC_CALCULATOR 1
#define FUNCTION_RESOLUTION 100000 //number of points on the graph







const int DISPLAY_BUFFER_LEN = MAX_Y*MAX_X/8;

//display 1602
//
#define commandMode 0
#define sendCommand 1
#define bit3 5
#define bit2 4
#define bit1 3
#define bit0 2
#define ledPin 25
#define MAX_INT_DIGITS 16
#define MAX_DECIMALS 3
#define MAX_EXPRESSION_SYMBOLS 28
//keypad
typedef char Symbol[10];
const int menu_b= 28;
const int pad1 = 27;
const int pad2 = 26;
const int pad3 =  22;
const int KEYCOMB[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
const int KEYCALC[4][4]={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'.','0','=','/'},
};

const int KEYCALC2[4][4]={
  {LOG,POW,ROOT,'0'},
  {SIN,COS,TAN,'0'},
  {LN,'(',')','0'},
  {'0','0','0','0'},
};
const int KEYCALC3[4][4]={
  {X,E,Pi,'0'},
  {'0','0','0','0'},
  {'0','0','0','0'},
  {'0','0','0','0'},
};
const int numb[4][4]={
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15},
};
char INPUT_ERROR_MSG[]="INPUT ERROR";
const int INPUT_ERROR=1;
const int ERROR_LEN_MAX=16;

const int (*KEYCALCS[3])[4][4]={&KEYCALC,&KEYCALC2,&KEYCALC3};

