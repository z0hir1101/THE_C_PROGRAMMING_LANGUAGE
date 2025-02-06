#include  <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *[], int);
void writelines(char *[], int);
void sort(char *[], int, int);

int main()
{
  int nlines;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    sort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort");
    return 1;
  }
}

int readlines(char *lineptr[], int ml)
{
  int ln, nlines, rdline(char *, int);
  char *p, line[MAXLEN], buf[MAXLEN * ml];

  nlines = 0;
  for (p = buf; (ln = rdline(line, MAXLEN)) > 1; p+=ln)
    if (nlines >= ml)
      return -1;
    else {
      line[ln-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void sort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  sort(v, left, last-1);
  sort(v, last+1, right);
}

int rdline(char *s, int lim)
{
  char *fch = s;

  while (--lim>0 && (*s=getchar())!=EOF && *s++!='\n')
    ;
  *s = '\0'; 
  return s-fch;
}

void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
