#include  <stdio.h>
#include  <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXVAL  100
#define NUMBER  '0'

double val[MAXVAL];
double *p = val;

int main(int argc, char *argv[])
{
  void push(double);
  double pop(void);
  char type;
  int op2;

  while (--argc > 0) {
    type = (isdigit(**++argv)) ? NUMBER : **argv;
    if (strlen(*argv) > 1)
      type = '\0'; 
    switch (type) {
      case NUMBER:
        push(atof(*argv));
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
        if (op2 != 0.0) push(pop() / op2);
        else printf("ERROR: zero divisior\n");
        break;
      default:
        printf("WRONG INPUT\n");
        break;
    }
  }
  printf("%f\n", pop());
  return 0;
}

void push(double f)
{
  if (p < val + MAXVAL)
    *p++ = f;
  else
    printf("push: stack full, cant push\n");
}

double pop(void)
{
  if (p > val)
    return *--p;
  printf("pop: stack is empty. cant get\n");
  return 0.0;
}
