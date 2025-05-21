#include "_font.h"



//display nokia
const int RST = 20;
const int CE = 19;
const int DC = 18;
const int DIN = 17;
const int CLK = 16;
const int MAX_X = 84;
const int MAX_Y = 48;
const int DISPLAY_BUFFER_LEN = MAX_Y*MAX_X/8
typedef uint8_t DisplayBuffer[MAX_X*MAX_Y/8];
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
const int pad1 = 16;
const int pad2 = 17;
const int KEYCOMB[][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
const int KEYCALC[][4]={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'.','0','=','/'},
};
const int KEYCALC2[][4]={
  {'(',')','0','0'},
  {'0','0','0','0'},
  {'0','0','0','0'},
  {'0','0','0','0'},
};
char INPUT_ERROR_MSG[]="INPUT ERROR";
const int INPUT_ERROR=1;
const int ERROR_LEN_MAX=16;

