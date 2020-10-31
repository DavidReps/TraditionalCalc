#include <stdio.h>

int takesNoArgs(char op);
float processMinus(float amt, float val);
float processPlus(float amt, float val);
float processOp(float amt, char op, float val);
float processTimes(float amt, float val);
float processDivide(float amt, float val);
float processPrint(float amt);
float processClear();


int main(){
  float amt = 0.0;  // the current value of the calculator
  char op;           // the operation to be performed
  float val;
  float s;        // the value of the operation

  while (1) {
            // Read an input line. The first char of each line is the operation.
            // Arithmetic operations are followed by whitespace and a number.
    char ic = getchar();
    if (ic < 0) {break;}   //EOF
    op = ic;
    if (op == 'Q') {break;}
    if (takesNoArgs(op)) {
      val = 0.0;
    }
    else{
      scanf("%f", &val);
    }
      while (1) {
        if (getchar() == '\n'){
        break;
        }
      }
            // Call a fn to process the op and its val.
      amt = processOp(amt, op, val);
        }
   return 0;
    }

int takesNoArgs(char op) {
  return (op == 'C') || (op == '=');
    }

float processOp(float amt, char op, float val) {
   if (op == '+') return processPlus(amt, val);
   else if (op == '-') return processMinus(amt, val);
   else if (op == '*') return processTimes(amt, val);
   else if (op == '/') return processDivide(amt, val);
   else if (op == '=') return processPrint(amt);
   else if (op == 'C') return processClear();
   else {
     printf("Bad Operator");
     return amt;
     }
  }
float processPlus(float amt, float val) {
  return amt + val;
}

float processMinus(float amt, float val) {
  return amt - val;
}
float processTimes(float amt, float val) {
  return amt * val;
}

float processDivide(float amt, float val) {
  return amt / val;
}

float processPrint(float amt) {
  printf("%f\n", amt);
  return amt;
}

float processClear() {
  return 0;
}
