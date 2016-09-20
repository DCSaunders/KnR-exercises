#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[], int str_len);
/*Print input to output, reversing each line*/

int main()
{
  int len;
  char line[MAXLINE];
  while((len = get_line(line, MAXLINE)) > 0)
    {
      reverse(line, len);
      printf("%s\n", line);
    }
  return 0;
}


int get_line(char s[], int maxline)
{
  int c, i;
  for (i=0; (i < maxline - 1) && (c=getchar()) != EOF && c != '\n'; ++i)
    {
      s[i] = c;
    }
   s[i] = '\0';
  return i - 1;
}

void reverse(char s[], int str_len)
{
  int i;
  char temp;
  for (i=0; i <= str_len / 2 ; ++i)
    {
        temp = s[i];
	s[i] = s[str_len - i];
	s[str_len - i] = temp;
    }
}
