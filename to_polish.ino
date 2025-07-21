int int_operator_to_precedence(int operatorT) {
  switch (operatorT) {
    case -1: // unary operator (negative number)
      return 101;
      break;
    case 2: // -
      return 1;
      break;
    case 3: // +
      return 1;
      break;
    case 4: // *
      return 2;
      break;
    case 5: // /
      return 2;
      break;
    
    
    default:
      //functions
      if(operatorT>=60){
        return 2;
        break;
      }
      return -100;
      break;

  }
}
void flushOperandStack(int output_operator_int[], float output_numbers_arr[], int * output_ptr, int holding_stack[], int * holding_stack_ptr) {
  //pops the top of the holding stack and pushes it to the op and number stack
  int_stack_push(output_operator_int, output_ptr, int_stack_pop(holding_stack, holding_stack_ptr));
  (*output_ptr)--;
  float_stack_push(output_numbers_arr, output_ptr, -100); //-100 is the operand in the number stack
}
void flushNumberStack(float output_numbers_arr[], int output_operator_int[], int * output_ptr, float number) {
  //pushes the number on the op stack and the number stack
  float_stack_push(output_numbers_arr, output_ptr,number);
  ( * output_ptr) --;
  int_stack_push(output_operator_int, output_ptr, -100); //-100 is the number in the operand stack
}
void to_polish(int input_operators_arr[], float input_numbers_arr[], int output_operators_arr[],float output_numbers_arr[], int * len,int*error) {
  //algoritmo che traduce la stringa passata in RPN

  //gestion del '-' come primo carattere
  int holding_stack[ * len], holding_stack_ptr = 0;
  int output_ptr = 0;
  int operator_precedence;
  int int_operator;
  for (int i = 0; i < * len; i++) {
    int_operator=input_operators_arr[i];
    if (int_operator==-100) {
      flushNumberStack(output_numbers_arr, output_operators_arr, & output_ptr, input_numbers_arr[i]);
    }
    else{
      //svuota l'holding stack fino a quando non puoi pushare l'operando su esso
      //( -> 0 
      //) -> 1
      if (int_operator == 0) {
        int_stack_push(holding_stack, & holding_stack_ptr, int_operator);
      } 
      else {
        if (int_operator == 1) {
          while (holding_stack_ptr > 0 && int_stack_peak(holding_stack, & holding_stack_ptr) != 0) {
            flushOperandStack(output_operators_arr, output_numbers_arr, & output_ptr, holding_stack, & holding_stack_ptr);
          }    
          if(holding_stack_ptr==0){
            (*error)=1;
            return ;
          }
          int_stack_pop(holding_stack, &holding_stack_ptr);
        } 
        else {

          while (holding_stack_ptr > 0 && int_stack_peak(holding_stack, & holding_stack_ptr) != 0 && int_operator_to_precedence(int_stack_peak(holding_stack, & holding_stack_ptr)) >= int_operator_to_precedence(int_operator)) {
            flushOperandStack(output_operators_arr, output_numbers_arr, & output_ptr, holding_stack, & holding_stack_ptr);
          }
          int_stack_push(holding_stack, & holding_stack_ptr, int_operator);
        }
      }
    }
  }


  while (holding_stack_ptr) {
    flushOperandStack(output_operators_arr, output_numbers_arr, & output_ptr, holding_stack, & holding_stack_ptr);
  }
  (*len)=output_ptr;
}
