#include <stdio.h>

void right_comment(int c);
void in_comment(int c);
void in_quote(int c);

int main()
{
  int c;
    while ((c = getchar()) != EOF)
    {
      if ((c == '\'') || (c == '"'))
	{
	    putchar(c);
	    in_quote(c);
	}
      else if (c=='/')
	{
	  c = getchar();
	  if (c == '/')
	    {
	    right_comment(c);
	    }
	  else if (c == '*')
	    {
	    in_comment(c);
	    }
	    else
	    {
	      putchar('/');
	      putchar(c);
	    }
	}
      else
	putchar(c);
    }
}

void right_comment(int c)
{
    while ((c = getchar()) != EOF)
    {
      if (c == '\n')
	return;
    }
}
  
void in_comment(int c)
{
    while ((c = getchar()) != EOF)
    {
      if (c == '*')
	{
	  if ((c = getchar()) == '/')
	    return;
	}
    }
}

  
void in_quote(int c)
{
  int initial_c = c;
   while ((c = getchar()) != EOF)
    {
      putchar(c);
      if (c == initial_c)
	return;
    }
}
