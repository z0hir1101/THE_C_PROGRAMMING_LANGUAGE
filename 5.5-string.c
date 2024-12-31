#include <stdio.h>

int main()
{
   void scat(char *s, char *t, int n);
   int scmp(char *s, char *t, int n);
   int send(char *s, char *t, int n);

   char s[20] = "yzzye";
   char t[20] = "yes";

   printf("%d\n", send(s, t, 2));
   return 0;
}

void scat(char *s, char *t, int n)
{
   for (; *s; s++)
      ;
   while ((*s++ = *t++) && n-- > 1) 
      ;
}

int scmp(char *s, char *t, int n)
{
   for (; *s == *t & n-- > 1; s++, t++)
      if (*s == '\0')
         return 0;
   return *s - *t;
}

int send(char *s, char *t, int n)
{
   char *fchar = t;

   for (; *s; s++)
      ;
   for (; *t && n-- > 0; t++)
      ;
   t--;
   s--;

   while (t >= fchar) 
      if (*s-- != *t--) 
         return 0;
   return 1; 
}
