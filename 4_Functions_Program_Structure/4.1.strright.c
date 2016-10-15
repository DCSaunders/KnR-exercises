#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int lim);
int strright(char source[], char searchfor[]);

int main()
{
  char pattern[] = "ould";
  char line[MAXLINE];
  int found = 0;
  while(getline(line, MAXLINE) > 0)
    {
      if (strright(line, pattern) >= 0)
	{
	  printf("%s\n", line);
	  found++;
	}
    }
  return found;
}

int getline(char line[], int lim)
{
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
      line[i++] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

int strright(char source[], char searchfor[])
{
  int index = -1;

  
}
