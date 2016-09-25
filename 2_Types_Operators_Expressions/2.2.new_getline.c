#include <stdio.h>
#define MAXLINE 1000
#define PRINTLINE 10

void copy(char to[], char from[]);
int get_line(char line[], int maxline);

/*Print all lines over 80 chars. Print longest input line separately*/

int main()
{
  int len, extralen;
  int max;
  char line[MAXLINE];
  char new[MAXLINE];
  char longest[MAXLINE];
  extralen = 1;
  max = 0;
  while((len = get_line(new, MAXLINE)) > 0)
    {
      copy(line, new);
      while (new[len] != '\n' && extralen > 0)
	{
	  if (extralen == MAXLINE)
	    copy(line, new);
	extralen = get_line(new, MAXLINE);
	len += extralen;
	}
    if (len > max){
      max = len;
      copy(longest, line);
	}
    if (len > PRINTLINE)
      printf("%s\n", line);
    }
  if (max > 0)
    printf("longest line: %s\n %d characters long\n", longest, max);
  return 0;
}


int get_line(char s[], int maxline)
{
  int c, i;
  for (i=0; i < maxline - 1; ++i)
    {
      if ((c=getchar()) == EOF)
    {
        break;
    }
      else if (c == '\n')
	{
	  break;
	}
      else
	{
	  s[i] = c;
	}
    }
  if (c=='\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i - 1;
}

void copy(char to[], char from[])
{
  int i;
  i=0;
  while((to[i] = from[i]) != '\0')
    ++i;
 }
