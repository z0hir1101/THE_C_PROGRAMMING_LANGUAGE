#include <stdio.h>

int main()
{
  void scat(char *, char *);
  int send(char *, char *);
  char s[20] = "hyello";
  char t[10] = "hello"; 
  printf("%d\n", send(s, t));
  return 0;
}

void scat(char *s, char *t)
{
  for (; *s; s++)
    ;
  while (*s++ = *t++) 
    ;
}

int send(char *s, char *t)
{
  char *fchar = t;
  for (; *s; s++)
    ; 
  for (; *t; t++)
    ; 

  while (t >= fchar) 
    if (*s-- != *t--) 
      return 0;
  return 1; 
}
