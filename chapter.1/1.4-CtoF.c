#include <stdio.h>

int main()
{
  float fahr, cels;
  int lower, upper, step;

  lower = -20;
  upper = 130;
  step = 20;

  cels = lower;
  while (cels <= upper) {
    fahr = (9.0/5.0) * cels + 32.0;
    printf("%5.1f | %4.1f\n", cels, fahr);
    cels += step;
  }
}
