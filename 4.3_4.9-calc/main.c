#include  <stdio.h>
#include <stdlib.h>
#include   <math.h>
#include   "calc.h"

#define MAXOP   100

int getop(char s[]);
void push(double);
void clstack(void);
double pop(void);

int main()
{
   int type;
   double op1, op2;
   char s[MAXOP];

   while ((type = getop(s)) != '=') {
      switch (type) {
         case NUMBER:
            push(atof(s));
            break;
         case '+':
            push(pop() + pop());
            break;
         case '*':
            push(pop() * pop());
            break;
         case '-':
            op2 = pop();
            push(pop() - op2);
            break;
         case '/':
            op2 = pop();
            if (op2 != 0.0)
               push(pop() / op2);
            else 
               printf("ERROR: zero divisior\n");
            break;
         case '%':
            op2 = pop();
            if (op2 != 0.0)
               push((int)pop() % (int)op2);
            else
               printf("ERROR: zero divisior\n");
            break;
         case '^':
            op2 = pop();
            op1 = pop();
            if (op1 == 0 && op2 <= 0)
               printf("ERROR: pow undefinded\n");
            else if (op1 < 0 && op2 - (int)op2 != 0)
               printf("ERROR: pow undefinded\n");
            else 
               push(pow(op1, op2));
            break;
         case '$':
            push(sin(pop()));
            break;
         case '!':
            push(exp(pop()));
            break;
         case '\n':
            printf("\t%.8g\n", pop());
            clstack();
            break;
      }
   }

   return 0;
}
