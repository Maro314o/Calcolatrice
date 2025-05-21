
int fromCharToNumber(char c){
  //from a char like '1','2','3',... returns its numeric value like 1,2,3
  return ((int)(c-'0'));
}
void fromFloatingToString(float number, char buffer[]); //TODO (unused)

void fromIntToString(int number,char buffer[]){
  //functions that transforms the number you put in in a string in the provided buffer es. 3 -> '3'

  itoa(number,buffer,10);
}
char keyToKey(const int keypad[][4],int key){
  //translates the key in to a provided keypad (4x4 matrix)
  return keypad[key/4][key%4];
}
int fromStrToInt(char num_str[]){
  // converts a string to and int
  int len=strlen(num_str);
  int num=0;
  for(int i=0;i<len;i++){
    num=num*10+fromCharToNumber(num_str[i]);
  }
  return num;
}
float fromStrToFloat(char num_str[]); //TODO (unused)

