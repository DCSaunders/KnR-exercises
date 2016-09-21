#include <stdio.h>

#define TABWIDTH 8

int main()
{
  int c, col, blank_count, blanks, tabs;
  col = 0;
  blank_count = 0;
  while((c=getchar()) != EOF)
    {
    if (c == ' ')
      {
	++col;
	++blank_count;
      }
    else
      {
	if (blank_count > 0)
	  {
	    if (blank_count == 1)
	      putchar(' ');
	    else
	      {
		tabs = col / TABWIDTH;
		blanks = col - tabs * TABWIDTH;
	for (int j = 0; j < tabs; ++j)
	  putchar('\t'); 
	for (int j = 0; j < blanks; ++j)
	  putchar(' ');
	      }
	  }
	putchar(c);
	blank_count = 0;
	if (c == '\n')
	  {
	    col = 0;
	  }
	 else
	  ++col;
      }
    }
  return 0;
}
