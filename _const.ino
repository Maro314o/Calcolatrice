#include "_font.h"
#include "displaybuffer.h"


//display nokia
const int RST = 20;
const int CE = 19;
const int DC = 18;
const int DIN = 17;
const int CLK = 16;

const int NUMBERS = 0;
const int FUNCTIONS= 1;
const int COSTANTS= 2;
const int MENU= 3;
const int LOG = 104;
const int ROOT = 232;
const int SIN = 107;
const int COS = 108;
const int TAN = 109;
const int LN = 110;
const int POW = 111;






const int DISPLAY_BUFFER_LEN = MAX_Y*MAX_X/8;

//display 1602
const int commandMode = 0;
const int sendCommand = 1;
const int bit3 = 5;
const int bit2 = 4;
const int bit1 = 3;
const int bit0 = 2;
const int ledPin = 25;
const int MAX_INT_DIGITS=16;
const int MAX_DECIMALS=3;
const int MAX_EXPRESSION_SYMBOLS=128;
//keypad
typedef char Symbol[10];
const int menu= 28;
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
  {X,E,PI,'0'},
  {'0','0','0','0'},
  {'0','0','0','0'},
  {'0','0','0','0'},
};
char INPUT_ERROR_MSG[]="INPUT ERROR";
const int INPUT_ERROR=1;
const int ERROR_LEN_MAX=16;

const int (*KEYCALCS[3])[4][4]={&KEYCALC,&KEYCALC2,&KEYCALC3};

