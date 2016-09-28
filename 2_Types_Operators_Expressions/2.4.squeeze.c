#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000

void squeeze(char s1[], char s2[]);

int main()
{
  int c, i;
  char s1[MAXLINE];
  char s2[MAXLINE];
  for (i=0; (i < MAXLINE - 1) && (c=getchar()) != EOF && c!= '\n'; i++)
    {
      s1[i] = c;
    }
  s1[i] = '\0';
  for (i = 0; (i < MAXLINE - 1) && (c=getchar()) != EOF && c!= '\n'; i++)
    {
      s2[i] = c;
    }
  s2[i] = '\0';
  printf("\n%s %s", s1, s2);
  squeeze(s1, s2);
  printf("\n%s %s", s1, s2);
  return 0;
}

void squeeze(char s1[], char s2[])
{
  char s2_chars[CHAR_MAX + 1];
  s2_chars[CHAR_MAX] = '\0';
  int i, j;
  i = j = 0;
  while (s2[i] != '\0')
    {
      s2_chars[s2[i++]] = '1';
    }
  i = 0; 
  while (s1[i] != '\0')
    {
      if (s2_chars[s1[i]] != '1')
	{
	  s1[j++] = s1[i];
	}
      i++;
    }
  s1[j] = '\0';
}

