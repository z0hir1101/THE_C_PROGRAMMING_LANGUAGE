#include    <stdio.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *[], int);
void writelines(char *[], int);
void qsort(char *[], int, int);

int main()
{
   int nlines;

   if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
      qsort(lineptr, 0, nlines-1);
      writelines(lineptr, nlines);
      return 0;
   } else {
      printf("error: input too big to sort");
      return 1;
   }
}
