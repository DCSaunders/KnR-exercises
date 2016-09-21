#include <stdio.h>

#define TABWIDTH 8

int main()
{
  int c, col, blanks;
  col = 0;
  while((c=getchar()) != EOF)
    {
    if (c == '\t')
      {
	blanks = TABWIDTH - (col % TABWIDTH);
	  for (int j = 0; j < blanks; ++j)
	    {
	      putchar(' ');
	    }
	  col += blanks;
      }
    else
      {
	putchar(c);
	if (c == '\n')
	  col = 0;
	else
	  ++col;
      }
    }
  return 0;
}
