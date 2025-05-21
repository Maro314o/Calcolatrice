//char queue

void char_queue_enqueue(char queue[],int *len,char element){
  queue[(*len)++]=element;
}

char char_queue_dequeue(char queue[],int *len){
  int element=queue[0];
  for(int i=0;i<*len-1;i++){
    queue[i]=queue[i+1];
  }
  (*len)--;
  return element;
}


//int queue


void int_queue_enqueue(int queue[],int *len,int element){
  queue[(*len)++]=element;
}

int int_queue_dequeue(int queue[],int *len){
  int element=queue[0];
  for(int i=0;i<*len-1;i++){
    queue[i]=queue[i+1];
  }
  (*len)--;
  return element;
}

//float queue

void float_queue_enqueue(float queue[],int *len,float element){
  queue[(*len)++]=element;
}

float float_queue_dequeue(float queue[],int *len){
  float element=queue[0];
  for(int i=0;i<*len-1;i++){
    queue[i]=queue[i+1];
  }
  (*len)--;
  return element;
}



