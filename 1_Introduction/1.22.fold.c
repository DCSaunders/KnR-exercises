#include <stdio.h>
# define MAXLEN   20
# define TABWIDTH 8
# define WRAP     1
int check_wrap(int col, int last_non_blank);

int main()
{
  int c, col, last_non_blank;
  col = last_non_blank = 0;
  while ((c = getchar()) != EOF)
    {
      if (c == ' ')
	{
	  ++col;
	}
      else if (c == '\t')
	{
	  col += TABWIDTH;
	}
      else if (c == '\n')
	{
	  putchar(c);
	  col = last_non_blank = 0;
	}
      else
	{
	  if (check_wrap(col, last_non_blank) != WRAP)
	    {
	      for (int j = last_non_blank; j<col; ++j)
		{
		  putchar(' ');
		}
	      last_non_blank = col;
	    }
	  else
	    {
	      col = last_non_blank = 0;
	    }
	  ++col;
	  last_non_blank = col;
	  putchar(c);
	}
    }
  return 0;
}


int check_wrap(int col, int last_non_blank)
{
  int wrap = 0;
  if (col + (col - last_non_blank + 1) > MAXLEN)
    {
      putchar('\n');
      wrap = WRAP;
    }
  return wrap;
}
