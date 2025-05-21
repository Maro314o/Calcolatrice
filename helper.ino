void matrix_copy(const int A[][4],int B[][4]){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      B[i][j]=A[i][j];
    }
  }
}
void array_copy(char A[],char B[]){
  int pos=0;
  while(A[pos]!='\0'){
    B[pos]=A[pos];
    pos++;
  }
  B[pos]='\0';
  
}
void BufferCopy(DisplayBuffer display_start ,DisplayBuffer display_end){
  for(int i=0;i<DISPLAY_BUFFER_LEN;i++){
      display_end[i]=display_start[i];
    }
  }


void BufferMerge(DisplayBuffer display_start ,DisplayBuffer display_end){
  for(int i=0;i<DISPLAY_BUFFER_LEN;i++){
      display_end[i]|=display_start[i];
    }
  }




void retrive_error(char error_buff[],int error){
  switch(error){
    case 1:
      array_copy(INPUT_ERROR_MSG,error_buff);
      break;
    default:
      break;
  }
}


void throw_error(char error[]){
  clearDisplay();
  writeWord(error);
  untilRead();
  clearDisplay();
}
