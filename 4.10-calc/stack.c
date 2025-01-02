#include  <stdio.h>
#include <string.h>
#define MAXVAL  100

static int sp = 0;
static double val[MAXVAL];

void push(double f)
{
   if (sp < MAXVAL)
      val[sp++] = f;
   else
      printf("push: stack full, cant push\n");
}

double pop(void)
{
   if (sp > 0)
      return val[--sp];
   else {
      printf("pop: stack is empty. cant get\n");
      return 0.0;
   }
}
