#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main()
{
  int c, len;
  char s[MAXLEN], t[MAXLEN];
  for (len = 0; ((c=getchar()) != EOF && c != '\n') && (len < MAXLEN); len++)
    {
      s[len] = c;
    }
  s[len] = '\0';
  expand(s, t);
  printf("%s\n", t);
  return 0;
}


void expand(char s1[], char s2[])
{
  int i, j, diff;
  i = j = diff = 0;
  int end = strlen(s1) - 1; 
  while (s1[i] != '\0')
    {
      if (s1[i + 1] == '-' && i + 1 < end)
	{
	  if (i + 1 < end)
	    {
	      while (s1[i] + diff != s1[i + 2])
		{
		s2[j++] = s1[i] + diff++;
		}
	      diff = 0;
	      i++;
	    }
	  else
	    {
	    s2[j++] = '-';
	    }
	}
      else
	{
	  s2[j++] = s1[i];
	}
      i++;
    }
  s2[j] = '\0';
}
