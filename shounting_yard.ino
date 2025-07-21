/*



   case '(':
   return -1 
   break;
   case ')':
   return 0
   break;
   case '-':
   return 1
   break;
   case '+':
   return 2
   break;
   case '*':
   return 3
   break;
   case '/':
   return 4
   break;
   default:
   return -100;
   break;


   }
   }

 */

float do_operation(float num1,float num2,int operatorT){
  switch(operatorT){
    case 2:
      return num1-num2;
      break;
    case 3:
      return num1+num2;
      break;

    case 4:
      return num1*num2;
      break;

    case 5:
      return num1/num2;
      break;
    case LOG:
      return log(num2)/log(num1);
    case ROOT:
      return pow(num2,1/num1);
      break;
    case POW:
      return pow(num1,num2);
      break;


    default:
      return 0;
  }

}
/*
 *
const int LOG = 104;
const int ROOT = 232;
const int SIN = 107;
const int COS = 108;
const int TAN = 109;
const int LN = 110;
 */
float do_function(float num1,int operatorT){
  switch(operatorT){
    case COS:
      return cos(num1);
    case SIN:
      return sin(num1);
    case TAN:
      return tan(num1);
    case LN:
      return log(num1);
    default:
      return 0;

    

  }

}
float shounting_yard(int operators[],float numbers[],int len,int *error,float variable){
  float number_stack[len];
  int number_stack_ptr=0;
  int risultato;
  float num1;
  float num2;
  for(int i=0;i<len;i++){
    if(operators[i]==-100){
      float_stack_push(number_stack,&number_stack_ptr,numbers[i]);
    }else if(operators[i]==X){
      float_stack_push(number_stack,&number_stack_ptr,variable);

    }
    else{
      //negative number operator
      if(operators[i]==-1){
        if(number_stack_ptr==0){
          (*error)=1;
          return -1;
        }

        num1=float_stack_pop(number_stack,&number_stack_ptr);
        float_stack_push(number_stack,&number_stack_ptr,-num1);

      }

    
    else{
      /*
       * outdated check for only 2 input operands
      if(number_stack_ptr<=1){
        (*error)=1;
        return -1;
      }
      */
      num1=float_stack_pop(number_stack,&number_stack_ptr);
      if(operators[i]>=107 && operators[i]<=110){
        float_stack_push(number_stack,&number_stack_ptr,do_function(num1,operators[i]));


      }else{
      num2=float_stack_pop(number_stack,&number_stack_ptr);
      float_stack_push(number_stack,&number_stack_ptr,do_operation(num2,num1,operators[i]));
      }
    }
    }
  }
  return number_stack[0];
}
