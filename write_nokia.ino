
void LcdWriteData(byte dat)
{
  digitalWrite(DC, HIGH); //DC pin is low for commands
  digitalWrite(CE, LOW);
  shiftOut(DIN, CLK, MSBFIRST, dat); //transmit serial data
  digitalWrite(CE, HIGH);
}

void LcdWriteCharacter(char character)
{
  for(int i=0; i<5; i++) LcdWriteData(ASCII[character - 0x20][i]);
  LcdWriteData(0x00);
}
void LcdWriteString(char *characters)
{
  while(*characters) LcdWriteCharacter(*characters++);
}


void LcdWriteCmd(byte cmd)
{
  digitalWrite(DC, LOW); //DC pin is low for commands
  digitalWrite(CE, LOW);
  shiftOut(DIN, CLK, MSBFIRST, cmd); //transmit serial data
  digitalWrite(CE, HIGH);
}

void LcdXY(int x, int y)
{
  LcdWriteCmd(0x80 | x);  // Column.
  LcdWriteCmd(0x40 | y);  // Row.
}


void clear_lcd(){
    for(int i=0; i<504; i++) LcdWriteData(0x00); 
}
void writeDisplayBuffer(DisplayBuffer display_buffer){
  LcdXY(0,0);
  for(int i=0;i<MAX_X*MAX_Y/8;i++){
    LcdWriteData(display_buffer[i]);
    
  }

}
int pixelFitsInDisplay(int x,int y){
  return x>= 0 && x<MAX_X && y>0 && y<MAX_Y;
}
int writePixelToDisplayBuffer(int x,int y,DisplayBuffer display_buffer){
  if(!pixelFitsInDisplay(x,y)){
    return 1;
  }
  int shift = y%8;
  int data_byte = 1<<shift;
  display_buffer[MAX_X*(y/8)+x]|=data_byte;
  return 0;
}
void drawLineToDisplayBuffer(int start_x,int start_y,int end_x,int end_y,DisplayBuffer display_buffer){
  
  int delta_x = end_x - start_x;
  int delta_y = end_y - start_y;
  int n_steps = max(abs(delta_y),abs(delta_x));
  
  float step_y = delta_y/(float)n_steps;
  float step_x = delta_x/(float)n_steps;
  

  for(int i=0;i<=n_steps;i++){
    writePixelToDisplayBuffer(start_x+i*step_x,start_y+i*step_y,display_buffer);
  }


}
void clearDisplayBuffer(DisplayBuffer display_buffer){
  for(int i=0;i<DISPLAY_BUFFER_LEN;i++){
    display_buffer[i]&=0;
  }
}
void test(){
    LcdWriteCmd(0x09);  // LCD all segments on
}
void NokiaError(char error[]){
  clear_lcd();
  LcdXY(20,3);
  LcdWriteString(error);
  delay(1000);
  clear_lcd();

  
}
