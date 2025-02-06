#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void sort(char *lineptr[], int left, int right,
    int (*comp)(void *, void*));
int numcmp(char *, char *);
int mystrcmp(char *, char *);

int numeric = 0;
int reverse = 0;
int fold = 0; 
int dir_order = 0;

int main(int argc, char *argv[])
{
  int c, nlines;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
      case 'n':
        numeric = 1;
        break;
      case 'r':
        reverse = 1;
        break;
      case 'f':
        fold = 1;
        break;
      case 'd':
        dir_order = 1;
        break;
        }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    sort((void **) lineptr, 0, nlines-1, 
          (int (*)(void*,void*))(numeric ? numcmp : mystrcmp));
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

void sort(char *v[], int left, int right, 
    int (*comp)(void *, void *))
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if (!reverse && (*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
    else if (reverse && (*comp)(v[i], v[left]) > 0)
      swap(v, ++last, i);
  swap(v, left, last);
  sort(v, left, last-1, comp);
  sort(v, last+1, right, comp);
}

int mystrcmp(char *s, char *t)
{
  int c1, c2;

  do {
    if (dir_order) {
      while (!isalnum(*s) && *s != ' ' && *s != '\0')
        s++;
      while (!isalnum(*t) && *t != ' ' && *t != '\0')
        t++;
    }
    if (*s == '\0')
      return 0;

    c1 = fold ? tolower(*s) : *s;
    c2 = fold ? tolower(*t) : *t;
    s++;
    t++;
  } while (c1 == c2); 

  return c1 - c2;
}

int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
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
