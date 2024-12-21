#include <stdio.h>

int main()
{
   void scat(char *, char *);
   int send(char *, char *);
   char s1[] = "hyello";
   char s2[] = "hello"; 
   printf("%d\n", send(s1, s2));
   return 0;
}

void scat(char *s, char *t)
{
   while (*s != '\0')
      s++;
   while (*s++ = *t++) 
      ;
}

int send(char *s, char *t)
{
   char *fchar = t;
   while (*s != '\0')
      s++;
   while (*t != '\0')
      t++;

   while (t >= fchar) 
      if (*s-- != *t--) 
         return 0;
   return 1; 
}
