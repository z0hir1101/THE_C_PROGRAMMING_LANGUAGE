#include  <stdio.h>
#include  <ctype.h>
#define BUFSIZE 100

static int buf[BUFSIZE];
static int bufp = 0;

int getch(void);
void ungetch(int c);

int main()
{
   int getfloat(double *);
   int getint(int *);
   double num;
   
   getfloat(&num);
   printf("%f\n", num);

   return 0;
}

int getfloat(double *pn)
{
   int c, pow, sign;

   while(isspace(c = getch()))
      ;
   if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {
      ungetch(c);
      return 0;
   }
   sign = (c == '-') ? -1 : 1;
   if ((c=='+' || c=='-') && !isdigit(c=getch())) {
      ungetch(c);
      return 0;
   }
   for (*pn = 0; isdigit(c); c=getch())
      *pn = 10 * *pn + (c - '0');
   if (c == '.')
      for (pow = 1; isdigit(c=getch()); pow*=10)
         *pn = 10 * *pn + (c - '0');
   *pn = *pn * sign / pow;
   if (c != EOF)
      ungetch(c);
   return c;
}

int getint(int *pn)
{
   int c, sign;

   while(isspace(c = getch()))
      ;
   if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {
      ungetch(c);
      return 0;
   }
   sign = (c == '-') ? -1 : 1;
   if ((c=='+' || c=='-') && !isdigit(c=getch())) {
      ungetch(c);
      return 0;
   }
   for (*pn = 0; isdigit(c); c=getch())
      *pn = 10 * *pn + (c - '0');
   *pn *= sign;
   if (c != EOF)
      ungetch(c);
   return c;
}

int getch()
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
   if (bufp > BUFSIZE)
      printf("ungetch: so many characters");
   else { 
      int i;
      for (i = bufp++; i > 0; --i)
         buf[i] = buf[i-1];
      buf[0] = c;
   }
}

