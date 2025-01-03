#include   <stdio.h>
#include  <stdlib.h>
#include    "calc.h"

#define MAXOP    100
#define MAXLINE 1000

int getop(char[], char[]);
int readline(char[], int);
void push(double);
double pop(void);

int main()
{
   extern int p;
   int type;
   double op1, op2;
   char s[MAXOP], line[MAXLINE];
   readline(line, MAXLINE);

   while ((type = getop(s, line)) != EOF) 
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
         case '\n':
            printf("\t%.8g\n", pop());
            readline(line, MAXLINE);
            p = 0;
            break;
         default:
            printf("WRONG INPUT\n");
            break;
      }
   return 0;
}

int readline(char s[], int lim)
{
   int c, i;

   i = 0;
   while (i<lim-1 && (c=getchar())!=EOF && c!='\n')
      s[i++] = c;
   if (c == '\n') {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}
