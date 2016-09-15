#include <stdio.h>

/* copy input to output and print details of EOF */

int main()
{
  int c;
  while ((c = getchar()) != EOF)
    {
      putchar(c);
    }
  printf("%d", EOF);
}
