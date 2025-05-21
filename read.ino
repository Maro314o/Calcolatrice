/*
   0  1  2  3 
   4  5  6  7
   8  9 10 11
   12 13 14 15
 */

int readKeypad() {
  //function that reads the current value typed on the keypad

  for (int col= 10; col< 14; col++) {  
    digitalWrite(col, HIGH);  
  }
  for (int col= 10; col< 14; col++) {  
    digitalWrite(col, LOW);  
    for (int row = 6 ;row< 10; row++) {  
      if (digitalRead(row) == LOW) {  
        return (row - 6) * 4 + (col - 10);  
      }
    }
    digitalWrite(col, HIGH);  
  }
  return -1;  
}
int untilRead(){
  //function that waits until it registers a keypress
  int key;
  do {
    key=readKeypad();
  }while(key==-1);
  delay(300);
  return key;
}
int untilReadPlusMode(){
  //function that waits until it registers a keypress
  int key;
  do {
    key=readKeypad();
    if(key==-1)
      key=(digitalRead(pad1)==LOW)?-1:16;
    if(key==-1)
      key=(digitalRead(pad2)==LOW)?-1:17;



  }while(key==-1);
  delay(300);
  return key;
}


