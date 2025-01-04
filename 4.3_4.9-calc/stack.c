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

double rop(void)
{
  if (sp > 0)
    return val[sp-1];
  else {
    printf("rop: stack is empty. cant read\n");
    return 0.0;
  }
}

void copy(char s[])
{
  int i;
  for (i = 0; i < strlen(s); ++i) {
    if (sp > MAXVAL) {
      printf("copy: stack full. cant copy\n");
      break;
    }
    val[sp++] = s[i];
  }
}

void chop(void)
{
  double tmp;
  if (sp > 1) {
    tmp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = tmp;
  }
  else 
    printf("chop: stack is empty.\n");  
}

void clstack(void)
{
  int i;
  for (i = 0; i < MAXVAL; ++i) 
    val[i] = 0.0;
} 
