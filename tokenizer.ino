
///-100 is forbidden from being used as an  operator
int char_operator_to_int_operator(char operatorT) {
  switch (operatorT) {
    case '(':
      return 0;
      break;
    case ')':
      return 1;
      break;
    case '-':
      return 2;
      break;
    case '+':
      return 3;
      break;
    case '*':
      return 4;
      break;
    case '/':
      return 5;
      break;
    default:
      if (operatorT >= 100) {
        return operatorT;
        break;
      }
      return -100;
      break;
  }
}
/*
 *
 *
 * #define X  20
#define E 21
#define Pi 22
*/
void check_correct_negative(int operators_arr[], float numbers_arr[],
                            int *len) {
  int int_operator;
  for (int i = 1; i < *len; i++) {
    int_operator = operators_arr[i];
    if (int_operator == char_operator_to_int_operator('-') &&
        operators_arr[i - 1] != -100 &&
        operators_arr[-1] != char_operator_to_int_operator(')')) {
      operators_arr[i] = -1;  // unary operator
      i++;
    }
  }
}
void parallelNumberPush(int input_operator_arr[], float input_numbers_arr[],
                        int *output_ptr, float *number, int *number_streak,
                        int *decimal) {
  int_stack_push(input_operator_arr, output_ptr, -100);
  (*output_ptr)--;
  float_stack_push(input_numbers_arr, output_ptr,
                   (*number));  //-100 is the operand in the number stack
  (*number) = 0;
  (*number_streak) = 0;
  (*decimal) = 0;
}
void parallelOperatorPush(int input_operator_arr[], float input_numbers_arr[],
                          int *output_ptr, int int_operator) {
  int_stack_push(input_operator_arr, output_ptr, int_operator);
  (*output_ptr)--;
  float_stack_push(input_numbers_arr, output_ptr,
                   -100);  //-100 is the operand in the number stack
}
void tokenize(char input_str[], int input_operator_arr[],
              float input_numbers_arr[], int *len, float variable) {
  // gestion del '-' come primo carattere
  if (input_str[0] == '-') {
    insert_head(input_str, len, '0');
  }
  float number = 0;
  int number_streak = 0;
  int output_ptr = 0;
  int int_operator;
  int decimal = 0;
  for (int i = 0; i < *len; i++) {
    // debug
    // clearDisplay();
    // displayStackFloat(input_numbers_arr,output_ptr);
    // displayStackInt(input_operator_arr,output_ptr);

    // leggere un numero anche di piu' cifre

    if (input_str[i] == E) {
      number = M_E;
      parallelNumberPush(input_operator_arr, input_numbers_arr, &output_ptr,
                         &number, &number_streak, &decimal);
    } else if (input_str[i] == Pi) {
      number = M_PI;
      parallelNumberPush(input_operator_arr, input_numbers_arr, &output_ptr,
                         &number, &number_streak, &decimal);

    } else if (input_str[i] == X) {
      number = variable;
      parallelNumberPush(input_operator_arr, input_numbers_arr, &output_ptr,
                         &number, &number_streak, &decimal);

    } else {
      if (input_str[i] >= '0' && input_str[i] <= '9') {
        if (!decimal) {
          number = number * 10 + (input_str[i] - '0');
        } else {
          number = number + ((float)(input_str[i] - '0') / pow(10, decimal++));
        }
        number_streak++;
      } else {
        if (input_str[i] == '.') {
          decimal = 1;
        } else {  // interpetazione del token

          // carica il numero e sincronizza gli stack
          if (number_streak) {
            parallelNumberPush(input_operator_arr, input_numbers_arr,
                               &output_ptr, &number, &number_streak, &decimal);
          }
          // svuota l'holding stack fino a quando non puoi pushare l'operando su
          // esso
          int_operator = char_operator_to_int_operator(input_str[i]);
          parallelOperatorPush(input_operator_arr, input_numbers_arr,
                               &output_ptr, int_operator);
        }
      }
    }
  }

  if (number_streak) {
    parallelNumberPush(input_operator_arr, input_numbers_arr, &output_ptr,
                       &number, &number_streak, &decimal);
  }
  (*len) = output_ptr;
  check_correct_negative(input_operator_arr, input_numbers_arr, len);
}
