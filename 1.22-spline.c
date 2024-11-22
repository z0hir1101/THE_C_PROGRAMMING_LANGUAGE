#include <stdio.h>
#define MAXLINE 1000
#define LIMIT 5

int readline(char line[], int maxlen);

int main()
{
	char line[MAXLINE];
	int len, cntr, i;
	
	while ((len = readline(line, MAXLINE)) > 1) {
		cntr = 1;
		for (i = 0; i < len; ++i) {
			putchar(line[i]);
			if (cntr >= LIMIT) {
				putchar('\n');
				cntr = 1;
				while (line[i] == ' ') ++i;
				--i;
			} else ++cntr;	
		}	
	}

   return 0;
}

int readline(char s[], int ml)
{
	int c, i;

	for (i = 0; i<ml-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i; 
} 
