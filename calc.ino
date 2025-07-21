
const int MAX_X = 84;
const int MAX_Y = 48;

typedef uint8_t DisplayBuffer[MAX_X * MAX_Y / 8];
void setup() { setup_fn(); }

void loop() {
  calcIni();

  untilRead();
  clearDisplay();
}
