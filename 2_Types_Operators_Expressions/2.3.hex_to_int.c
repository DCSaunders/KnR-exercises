#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

void htoi(char s[], int len);

int main()
{
  int c, i;
  char s[MAXLINE];

  while (MAXLINE)
    {
  for (i=0; (i < MAXLINE - 1) && (c=getchar()) != EOF && c != '\n'; ++i)
    {
      if (isdigit(c) || ('a' <= tolower(c) && tolower(c) <= 'f') || (i == 1 && (tolower(c) == 'x')))
	  s[i] = c;
       else
	    {
	      printf("Invalid character %c", c);
	    }
    }
  s[i] = '\0';
  htoi(s, i - 1);
    }
  return 0;
}

void htoi(char s[], int len)
{
  int total, c;
  total = 0;
  int product = 1;
  for (int i = 0; i <=len; ++i)
    {
      c = s[len - i];
      if (tolower(c) != 'x')
	{
	  if ('a' <= tolower(c) && tolower(c) <= 'f')
	    {
	      c = tolower(c) - 'a' + 10;
	    }
	  else
	    {
	      c = c - '0';
	    }
	  total += c * product;
	}
      product *= 16;
    }
  printf("%d\n", total);
}

