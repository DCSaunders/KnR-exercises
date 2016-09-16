#include <stdio.h>

/* Copy input to output, truncating spaces to a maximum of one */
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
