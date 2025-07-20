void setBits(int b3, int b2, int b1, int b0) {
  //function that sets bits to the display to display  a
  digitalWrite(bit3, b3);
  digitalWrite(bit2, b2);
  digitalWrite(bit1, b1);
  digitalWrite(bit0, b0);
  delay(2);
  digitalWrite(sendCommand, HIGH);
  delay(2);
  digitalWrite(sendCommand, LOW);
  delay(2);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);
  digitalWrite(bit0, LOW);
  delay(2);
}
void writeLetter(char c){
  //function that sends a character to the display 4bit at a time
  setBits((c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1);
  setBits((c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);

}
void writeWord(char parola[]){
  //function that sends a string to the display
  int str_length = strlen(parola); 

  for (int i = 0; i < str_length; i++) {
    writeLetter(parola[i]);
  }
}
void writeInt(int numero){
  char string_buffer[MAX_INT_DIGITS];
  fromIntToString(numero,string_buffer);
  writeWord(string_buffer);
}
void writeFloat(float numero){
  //3 digit of floating point precision
  int whole_part;
  int decimal_part;
  if(numero<0 && numero> -1) {
    writeLetter('-');
  }
  whole_part=(int)numero;

  decimal_part=abs((((float) numero)-whole_part))*(pow(10,MAX_DECIMALS));
  writeInt(whole_part);
  writeLetter('.');
  writeInt(decimal_part);
}

void clearDisplay(){
  //clears the display
  digitalWrite(commandMode, LOW);
  setBits(0, 0, 0, 0);
  setBits(0, 0, 0, 1);
  digitalWrite(commandMode, HIGH);
}

