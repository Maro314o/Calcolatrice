char displayAndReturnsymbol(int number, int keypad[][4]) {
  // takes a number from the input keypad,translates in a number in te keycalc
  // keypad,prints it and then return it' value
  char keypad_char_value = keyToKey(keypad, number);
  switch (keypad_char_value) {
    case LOG: {
      char buffer[] = "LOG";

      writeWord(buffer);

    } break;
    case SIN: {
      char buffer[] = "SIN";

      writeWord(buffer);

    } break;
    case COS: {
      char buffer[] = "COS";

      writeWord(buffer);

    } break;
    case TAN: {
      char buffer[] = "TAN";

      writeWord(buffer);

    } break;
    case LN: {
      char buffer[] = "LN";

      writeWord(buffer);

    } break;
    case POW: {
      char buffer[] = "^";
      writeWord(buffer);
    } break;

    default:

      if (keypad_char_value != '=') {
        writeLetter(keypad_char_value);
      }
      break;
  }
  return keypad_char_value;
}
float evaluate(char expression[], int expression_ptr,int * error) {
  int output_operands[MAX_EXPRESSION_SYMBOLS];
  float output_numbers[MAX_EXPRESSION_SYMBOLS];
  int input_operands[MAX_EXPRESSION_SYMBOLS];
  float input_numbers[MAX_EXPRESSION_SYMBOLS];

  tokenize(expression, input_operands, input_numbers, &expression_ptr);
  // displayStackFloat(input_numbers,expression_ptr);
  // displayStackInt(input_operands,expression_ptr);
  to_polish(input_operands, input_numbers, output_operands, output_numbers,
            &expression_ptr, error);
  if (*error) {
    return NULL;
  }
  // displayStackFloat(output_numbers,expression_ptr);
  // displayStackInt(output_operands,expression_ptr);

  float result =
      shounting_yard(output_operands, output_numbers, expression_ptr, error);
  if (*error) {
    return NULL;
  }

  return result;
}
void calcIni() {
  char symbol = 0;
  int key = 0;
  int menu = 0;
  char expression[MAX_EXPRESSION_SYMBOLS];
  int output_operands[MAX_EXPRESSION_SYMBOLS];
  float output_numbers[MAX_EXPRESSION_SYMBOLS];
  int input_operands[MAX_EXPRESSION_SYMBOLS];
  float input_numbers[MAX_EXPRESSION_SYMBOLS];
  int expression_ptr = 0;
  int keypad[4][4];
  int error = 0;
  int current_keypad = NUMBERS;
  char error_buff[ERROR_LEN_MAX];
  matrix_copy(KEYCALC, keypad);
  writeDisplayBuffer(*BUFFER_LIST[NUMBERS]);
  do {
    key = untilReadPlusMode();
    if (key == 19) {
      menu = 1 - menu;
    } else if (key >= 16) {
      matrix_copy(*KEYCALCS[key - 16], keypad);
      current_keypad = key - 16;
      if (menu) {
      } else {
        writeDisplayBuffer(*BUFFER_LIST[key - 16]);
      }
    } else {
      symbol = displayAndReturnsymbol(key, keypad);

      if (symbol != '=') expression[expression_ptr++] = symbol;
      if (current_keypad != NUMBERS) {
        matrix_copy(*KEYCALCS[NUMBERS], keypad);
        current_keypad = NUMBERS;
        if (!menu) {
          writeDisplayBuffer(*BUFFER_LIST[NUMBERS]);
        }
      }
    }

  } while (symbol != '=');
  clearDisplay();
  tokenize(expression, input_operands, input_numbers, &expression_ptr);
  // displayStackFloat(input_numbers,expression_ptr);
  // displayStackInt(input_operands,expression_ptr);
  to_polish(input_operands, input_numbers, output_operands, output_numbers,
            &expression_ptr, &error);
  if (error) {
    retrive_error(error_buff, error);
    throw_error(error_buff);
    return;
  }
  // displayStackFloat(output_numbers,expression_ptr);
  // displayStackInt(output_operands,expression_ptr);

  float result =
      shounting_yard(output_operands, output_numbers, expression_ptr, &error);
  if (error) {
    retrive_error(error_buff, error);
    throw_error(error_buff);
    return;
  }

  if (result == ((float)((int)result)))
    writeInt(result);
  else
    writeFloat(result);

  return;
}
