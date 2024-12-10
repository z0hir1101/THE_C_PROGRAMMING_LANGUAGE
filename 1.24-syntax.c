#include   <stdio.h>
#include  <string.h>
#define MAXSIZE 1000

int isbrackets (char array[]);
int iscomments (char array[]);
int ismarks (char array[]);

int main()
{
   char array[MAXSIZE];
   int len, c;
   
   len = 0;
   while ((c = getchar()) != EOF && c != '~') {
      array[len] = c;
      ++len; 
   }

   if (isbrackets(array))
      printf("error in brackets\n");
   if (iscomments(array))
      printf("error in comments\n");
   if (ismarks(array))
      printf("error in marks\n"); 
   return 0;
}

int isbrackets (char s[])
{
   int i, j, cntr;
   cntr = 0;

   for (i = 0; i < strlen(s); ++i) {
      cntr = 0;
      if (s[i]!='[' && s[i]!='{' && s[i]!='(') {
         for (j = i+1; j < strlen(s); ++j) {
            if (s[i]=='(' && s[j]-s[i] == 1)
               ++cntr;
            else if (s[j] - s[i] == 2)
               ++cntr;
         }
         if (cntr <= 0) return 1;
      }
      if (s[i]!=']' && s[i]!='}' && s[i]!=')') {
         for (j = 0; j < i; ++j) {
            if (s[i]=='(' && s[i]-s[j] == 1)
               ++cntr;
            else if (s[i] - s[j] == 2)
               ++cntr;
         }
         if (cntr <= 0) return 1;
      }
      return 0;
   }

   return 0;
}

int iscomments(char s[])
{
   int i, j, cntr;

   for (i = 1; i < strlen(s); ++i) {
      cntr = 0;
      if (s[i-1] != '/' || s[i] != '*')
         continue;
      for (j = i; j < strlen(s); ++j) 
         if (s[j] == '/' && s[j-1] == '*')
            ++cntr;
      if (cntr <= 0) return 1;
   }
   return 0;
}

int ismarks(char s[])
{
   int i, j, cntr;

   for (i = 0; i < strlen(s); ++i) {
      cntr = 0;
      if (s[i] != '"' && s[i] != 39)
         continue;
      for (j = i+1; j < strlen(s); ++j) 
         if (s[j] == s[i])
            ++cntr;
      if (cntr <= 0) return 1;
   }
   return 0;
}
