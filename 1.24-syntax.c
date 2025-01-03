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
   while ((c = getchar()) != EOF) {
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
   int i, j, isclose, cntrOP, cntrCL;
   cntrOP = cntrCL = 0;

   for (i = 0; i < strlen(s); ++i) {
      isclose = 0;
      if (s[i]=='[' || s[i]=='{' || s[i]=='(') {
         for (j = i+1; j < strlen(s); ++j)
            if ((s[i]=='(' && s[j]-s[i] == 1) || 
                (s[i]!='(' && s[j]-s[i] == 2)) { 
               isclose = 1;
               break;
            } 
         if (!isclose) return 1;
      } else if (s[i]==']' || s[i]=='}' || s[i]==')') {
         for (j = 0; j < i; ++j)
            if ((s[i]==')' && s[i]-s[j] == 1) || 
                (s[i]!=')' && s[i]-s[j] == 2)) { 
               isclose = 1;
               break;
            } 
         if (!isclose) return 1;
      }
   }

   for (i = 0; i < strlen(s); ++i) 
      if (s[i]=='[' || s[i]=='{' || s[i]=='(') cntrOP++;
      else if (s[i]==']' || s[i]=='}' || s[i]==')') cntrCL++; 
   
   return (cntrOP == cntrCL) ? 0 : 1;
}

int iscomments(char s[])
{
   int i, j, cntr;

   for (i = 1; i < strlen(s); ++i) {
      cntr = 0;
      if (s[i-1] != '/' || s[i] != '*')
         continue;
      for (j = i; j < strlen(s); ++j) 
         if (s[j] == '/' && s[j-1] == '*') ++cntr;
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
         if (s[j] == s[i]) ++cntr;
      if (cntr <= 0) return 1;
   }
   return 0;
}
