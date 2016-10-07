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
  printf("%s", s);
  return 0;
}

void escape(char s[], char t[])
{
}  
void rescape(char s[], char t[])
{
}
