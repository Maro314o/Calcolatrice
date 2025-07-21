char displayAndReturnsymbol(int number, int keypad[][4]) {
  // takes a number from the input keypad,translates in a number in te keycalc
  // keypad,prints it and then return it' value
  char keypad_char_value = keyToKey(keypad, number);
  switch (keypad_char_value) {
    case X: {
      char buffer[] = "X";

      writeWord(buffer);

    } break;
    case E: {
      char buffer[] = "e";

      writeWord(buffer);

    } break;
    case Pi: {
      char buffer[] = {247, 0};

      writeWord(buffer);

    } break;
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
float evaluate(char expression[], int expression_ptr, int* error,
               float variable) {
  int output_operands[MAX_EXPRESSION_SYMBOLS];
  float output_numbers[MAX_EXPRESSION_SYMBOLS];
  int input_operands[MAX_EXPRESSION_SYMBOLS];
  float input_numbers[MAX_EXPRESSION_SYMBOLS];

  tokenize(expression, input_operands, input_numbers, &expression_ptr,
           variable);
  // displayStackFloat(input_numbers,expression_ptr);
  // displayStackInt(input_operands,expression_ptr);
  to_polish(input_operands, input_numbers, output_operands, output_numbers,
            &expression_ptr, error);
  if (*error) {
    return 0.0;
  }
  // displayStackFloat(output_numbers,expression_ptr);
  // displayStackInt(output_operands,expression_ptr);

  float result =
      shounting_yard(output_operands, output_numbers, expression_ptr, error);
  if (*error) {
    return 0.0;
  }

  return result;
}
void zoom(float coords[], float factor) {
  factor=1/factor;
  float xRange = MAX_X * factor;
  float yRange = MAX_Y * factor;

  float xMin = -xRange / 2.0;
  float xMax = +xRange / 2.0;
  float yMin = -yRange / 2.0;
  float yMax = +yRange / 2.0;
  coords[0] = (coords[0] - xMin) / (xMax - xMin) * MAX_X;
  coords[1] = (coords[1] - yMin) / (yMax - yMin) * MAX_Y;
}
void write_function_to_buffer(DisplayBuffer function_display, char expression[],
                              int expression_ptr, int* error) {
  int test = 0;
  float coords[2];
  float step = MAX_X / ((float)FUNCTION_RESOLUTION);
  float value;
  float x, y;
  for (float i = -(MAX_X / 2.0); i < MAX_X / 2.0; i += step) {
    value = evaluate(expression, expression_ptr, error, i);
    coords[0] = i;
    coords[1] = value;
    zoom(coords, 4);

    x = coords[0];
    y = coords[1];

    test += writePixelToDisplayBuffer(x+1, 48 - y, function_display);
  }
  BufferMerge(function_graph_bg, function_display);
  writeNumber(test);
}

void calcIni() {
  float result;
  char symbol = 0;
  int key = 0;
  int menu = 0;
  int mode = SCIENTIFIC_CALCULATOR;
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
      writeDisplayBuffer(*BUFFER_LIST[key - 16]);
    }

    else {
      if (menu) {
        matrix_copy(*KEYCALCS[NUMBERS], keypad);
        current_keypad = NUMBERS;
        writeDisplayBuffer(*BUFFER_LIST[NUMBERS]);
        menu = 0;
        expression_ptr = 0;
        switch (keyToKey(numb, key)) {
          case 0:
            mode = SCIENTIFIC_CALCULATOR;
            break;
          case 1:
            mode = GRAPHIC_CALCULATOR;
            break;
          default:
            mode = SCIENTIFIC_CALCULATOR;
        }

      } else {
        symbol = displayAndReturnsymbol(key, keypad);

        if (symbol != '=') expression[expression_ptr++] = symbol;
        if (current_keypad != NUMBERS) {
          matrix_copy(*KEYCALCS[NUMBERS], keypad);
          current_keypad = NUMBERS;
          writeDisplayBuffer(*BUFFER_LIST[NUMBERS]);
        }
      }
    }

    if (menu) {
      writeDisplayBuffer(functionality_menu);
    }

  } while (symbol != '=');
  clearDisplay();
  switch (mode) {
    case SCIENTIFIC_CALCULATOR:
      result = evaluate(expression, expression_ptr, &error, 0);
      CHECK_ERROR_MACRO(error, error_buff);
      writeNumber(result);
      return;
    case GRAPHIC_CALCULATOR:

      clearDisplayBuffer(functions_canvas);
      write_function_to_buffer(functions_canvas, expression, expression_ptr,
                               &error);
      CHECK_ERROR_MACRO(error, error_buff);
      writeDisplayBuffer(functions_canvas);
      return;
    default:
      return;
  }
}
