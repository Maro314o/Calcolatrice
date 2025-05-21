
void setup_fn(){

  //keypad
  pinMode(commandMode, OUTPUT);
  pinMode(sendCommand, OUTPUT);
  pinMode(pad1, INPUT_PULLDOWN);
  pinMode(pad2, INPUT_PULLDOWN);

  // Set keypad rows (pins 6 to 9) as INPUT_PULLUP
  for (int i = 6; i < 10; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  // Set keypad columns (pins 10 to 13) as OUTPUT
  for (int i = 10; i < 14; i++) {
    pinMode(i, OUTPUT);
  }

  //lcd
  pinMode(bit3, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit1, OUTPUT);
  pinMode(bit0, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(commandMode, LOW);
  delay(2);

  // 4-bit mode
  setBits(0, 0, 1, 0);
  // Clear display
  setBits(0, 0, 0, 0);
  setBits(0, 0, 0, 1);
  // Return home
  setBits(0, 0, 0, 0);
  setBits(0, 0, 1, 0);
  // Display on, no cursor
  setBits(0, 0, 0, 0);
  setBits(1, 1, 0, 0);
  // Text mode
  digitalWrite(commandMode, HIGH);
  digitalWrite(ledPin, HIGH);


  //nokia
  pinMode(RST, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(RST, LOW);
  digitalWrite(RST, HIGH);
  
  LcdWriteCmd(0x21);  // LCD extended commands
  LcdWriteCmd(0xBF);  // set LCD Vop (contrast)
  LcdWriteCmd(0x04);  // set temp coefficent
  LcdWriteCmd(0x14);  // LCD bias mode 1:40
  LcdWriteCmd(0x20);  // LCD basic commands
  LcdWriteCmd(0x0C);  // LCD normal video
  clear_lcd();
}
