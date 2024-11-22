#include   <stdio.h>
#define MAXLINE 1000
#define IN         1
#define OUT        0

void rmcomments(char line[], int len);
int readline(char line[], int maxlen);

int main()
{
   int len, i;
   char line[MAXLINE];

   while ((len = readline(line, MAXLINE)) > 1) {
      rmcomments(line, len);
      for (i = 0; i < len; ++i) 
         if (line[i] != '\0')
            putchar(line[i]);
   }
   return 0;
}

void rmcomments(char s[], int len)
{
	int i, state;
	state = OUT;

	for (i = 1; i < len-1; ++i) {
		if (state==OUT && s[i]=='/' && s[i+1]=='*' && s[i-1]!='"') {
			state = IN;
         s[i] = '\0';
         s[i+1] = '\0';
         ++i;
      }
      else if (state==IN && s[i]=='*' && s[i+1]=='/') {
         state = OUT; 
         s[i] = '\0';
         s[i+1] = '\0';
         ++i;  
      }
      else if (state == IN)
         s[i] = '\0';
   }
}

int readline(char s[], int max)
{
  int c, i;

  for (i = 0; i<max-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }
  return i;
}
