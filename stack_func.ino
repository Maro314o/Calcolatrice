// char stacks
void char_stack_push(char stack[],int * len,char element){
  stack[(*len)++]=element;
}
char char_stack_pop(char stack[],int * len){
  return stack[--(*len)];
}
char char_stack_peak(char stack[],int * len){
  return stack[(*len)-1];
}



//int stacks


void int_stack_push (int stack[],int * len,int element){
  stack[(*len)++]=element;
}
int int_stack_pop(int stack[],int * len){
  return stack[--(*len)];
}
int int_stack_peak(int stack[],int * len){
  return stack[(*len)-1];
}

//float stacks 


void float_stack_push (float stack[],int * len,float element){
  stack[(*len)++]=element;
}
float float_stack_pop(float stack[],int * len){
  return stack[--(*len)];
}
float float_stack_peak(float stack[],int * len){
  return stack[(*len)-1];
}


