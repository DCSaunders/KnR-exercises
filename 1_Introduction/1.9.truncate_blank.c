#include <stdio.h>

/* count blank characters in input */
int main()
{
  int c;
    while((c = getchar()) != EOF)
    {
      putchar(c);
      if (c == ' ')
	{
	  while ((c = getchar()) == ' ');
	  putchar(c);
	}
    }
}
