#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline_new(char line[], int lim);
int strright(char source[], char searchfor[]);

int main()
{
  char pattern[] = "ould";
  char line[MAXLINE];
  int found = 0;
  int index;
  while(getline_new(line, MAXLINE) > 0)
    {
      index = strright(line, pattern);
      if (index >= 0)
	{
	  printf("%s %d\n", line, index);
	  found++;
	}
    }
  return found;
}

int getline_new(char line[], int lim)
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
  int sourcelen = strlen(source);
  int searchlen = strlen(searchfor);
  int j = searchlen - 1;
  for (int i = sourcelen - 1; i>=0; i--)
    {
      if (source[i] != searchfor[j])
	{
	  if (j < (searchlen - 1))
	  j = searchlen - 1;
	}
	else if (j > 0)
	  {
	    j--;
	  }
	else if (j == 0)
	  {
	    index = i;
	    break;
	  }
    }
  return index;
}
