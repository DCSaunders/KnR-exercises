#include <stdio.h>
#define MAXLEN 1000

void escape(char s[], char t[]);
void rescape(char s[], char t[]);

int main()
{
  int c, len;
  char s[MAXLEN], t[MAXLEN];
  for (len = 0; ((c=getchar()) != EOF) && (len < MAXLEN); len++)
    {
      s[len] = c;
    }
  s[len] = '\0';
  escape(s, t);
  printf("%s", t);
  return 0;
}

void escape(char s[], char t[])
{
  int i, j;
  i = j = 0;
  while (s[i] != '\0')
    {
      switch (s[i])
	{
	case '\n':
	  t[j++] = '\\';
	  t[j] = 'n';
	  break;
	case '\t':
	  t[j++] = '\\';
	  t[j] = 't';
	  break;
	default:
	  t[j] = s[i];
	}
      i++;
      j++;
    }
  t[j] = '\0';
}
void rescape(char s[], char t[])
{
  int i, j;
  i = j = 0;
  while (s[i] != '\0')
    {
      switch (s[i])
	{
	case '\\':
	  switch(s[i+1])
	    {
	    case 'n':
	      t[j] = '\n';
	      i++;
	      break;
	    case 't':
	      t[j] = '\t';
	      i++;
	      break;
	    }
	default:
	  t[j] = s[i];
	}
      i++;
      j++;
    }
  t[j] = '\0';
}
