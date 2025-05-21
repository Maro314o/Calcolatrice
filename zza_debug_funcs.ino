
void displayStackInt(int arr[],int ptr){
  for(int i=0;i<ptr;i++){
    writeInt(arr[i]);
  }
  untilRead();
  clearDisplay();
}
void displayStackFloat(float arr[],int ptr){
  for(int i=0;i<ptr;i++){
    writeFloat(arr[i]);
    writeLetter(' ');
  }
  untilRead();
  clearDisplay();
}
