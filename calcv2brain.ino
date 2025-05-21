char displayAndReturnsymbol(int number,int keypad[][4]){
  //takes a number from the input keypad,translates in a number in te keycalc keypad,prints it and then return it' value
  char keypad_char_value=keyToKey(keypad,number);
  if(keypad_char_value!='='){
    writeLetter(keypad_char_value);
  }
  return keypad_char_value;
}
void calcIni(){
  char symbol;
  char expression[MAX_EXPRESSION_SYMBOLS];
  int output_operands[MAX_EXPRESSION_SYMBOLS];
  float output_numbers[MAX_EXPRESSION_SYMBOLS];
  int input_operands[MAX_EXPRESSION_SYMBOLS];
  float input_numbers[MAX_EXPRESSION_SYMBOLS];
  int expression_ptr=0;
  int keypad[4][4];
  int error=0;
  char error_buff[ERROR_LEN_MAX];
  matrix_copy(KEYCALC,keypad);
  do {
    symbol=untilReadPlusMode();
    if(symbol==16){
      matrix_copy(KEYCALC,keypad);
    }
    if(symbol==17){
      matrix_copy(KEYCALC2,keypad);
    }

    if(symbol!=16 && symbol!= 17){
      symbol=displayAndReturnsymbol(symbol,keypad);

      if(symbol!='=') expression[expression_ptr++]=symbol;
    }

  }while(symbol!='=');
  clearDisplay();
  tokenize(expression,input_operands,input_numbers,&expression_ptr);
  //displayStackFloat(input_numbers,expression_ptr);
  //displayStackInt(input_operands,expression_ptr);
  to_polish(input_operands,input_numbers,output_operands,output_numbers,&expression_ptr,&error);
  if(error){
    retrive_error(error_buff,error);
    throw_error(error_buff);
    return;
  }
  //displayStackFloat(output_numbers,expression_ptr);
  //displayStackInt(output_operands,expression_ptr);

  float result=shounting_yard(output_operands,output_numbers,expression_ptr,&error);
  if(error){
    retrive_error(error_buff,error);
    throw_error(error_buff);
    return;
  }

  if(result==((float)((int)result)))writeInt(result);
  else writeFloat(result);
  return;





}
