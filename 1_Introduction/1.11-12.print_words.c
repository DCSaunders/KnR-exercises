#include <stdio.h>

#define IN  1
#define OUT 0

/* Prints input to output one word at a time */

int main()
{
  int c, state;
  state = OUT;
    while ((c = getchar()) != EOF)
      {
	if (c == ' ' || c == '\t' || c == '\n')
	  {
	    state = OUT;
	  }
	else if (state == OUT)
	  {
	    putchar('\n');
	    state = IN;
	    putchar(c);
	  }
	else
	  putchar(c);
      }
}
