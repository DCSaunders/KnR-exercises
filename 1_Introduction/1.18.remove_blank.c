#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

/*Print input to output, deleting blank lines and trailing whitespace*/

int main()
{
  int len;
  char line[MAXLINE];
  while((len = get_line(line, MAXLINE)) > 0)
    {
      printf("%s\n", line);
    }
  return 0;
}


int get_line(char s[], int maxline)
{
  int c, i, j;
  for (i=0; (i < maxline - 1) && (c=getchar()) != EOF && c != '\n'; ++i)
    {
      s[i] = c;
    }
  j = i - 1;
  while((s[j]=='\t') || (s[j] == ' ')|| (s[j]==EOF) || (s[j]=='\n'))
    --j;
   s[j+1] = '\0';
  return j+1;
}
