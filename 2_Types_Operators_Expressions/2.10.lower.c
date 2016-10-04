#include <stdio.h>

int main()
{
  int c;
  int diff = 'A' - 'a';
  while ((c=getchar()) != EOF)
    {
      putchar(('A' <= c && c<= 'Z')? c - diff : c);
    }
  return 0;
}
