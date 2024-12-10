#include   <stdio.h>
#define MAXLINE 1000

int readline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len, max, isbigger, c;
  char line[MAXLINE];
  char longest[MAXLINE];
  
  max = 0;
  while ((len = readline(line, MAXLINE)) > 1) {
    isbigger = 0; 
    for (int i = 0; i < MAXLINE; ++i) {
      if (line[i] == '\n')
        isbigger = 1;
    }
    if (isbigger == 0) {
      while ((c = getchar()) != EOF && c != '\n')
        ++len;
      if (c == '\n')
        ++len;
    }
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)
    printf("%s - %d\n", longest, max);
  return 0;
}

int readline(char s[], int lim)
{
  int c, i;

  for (i = 0; i<lim-1 && (c = getchar())!= EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;
  
  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}

