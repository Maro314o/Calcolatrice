void insert_n(char V[],int *len,int position,char element){
  for(int i=*len;i>position;i--){
    V[i]=V[i-1];
  }
  (*len)++;
  V[position]=element;
}
void insert_head(char V[],int *len,char element){
  insert_n(V,len,0,element);
}



//float 
void insert_n_float(float V[],int *len,int position,float element){
  for(int i=*len;i>position;i--){
    V[i]=V[i-1];
  }
  (*len)++;
  V[position]=element;
}

void remove_n_float(float V[],int *len,int position){
  for(int i=position;i<(*len)-1;i--){
    V[i]=V[i+1];
  }
  (*len)--;
}
//int 

void insert_n_int(int V[],int *len,int position,int element){
  for(int i=*len;i>position;i--){
    V[i]=V[i-1];
  }
  (*len)++;
  V[position]=element;
}
void remove_n_int(int V[],int *len,int position){
  for(int i=position;i<(*len)-1;i--){
    V[i]=V[i+1];
  }
  (*len)--;
}
