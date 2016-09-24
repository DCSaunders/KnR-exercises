#include <stdio.h>

void right_comment(int c);
void in_comment(int c);
void in_quote(int c);

/* TODO
Should just ignore syntax errors when in quotes and comments
Should not putchar() anywhere
Maybe keep track of pos, and optionally pass to an error function.
Keep counts for parentheses, brackets and braces
 */

int main()
{
  int c, parens, braces, brackets;
  parens = braces = brackets = 0;
    while ((c = getchar()) != EOF)
    {
      if (c == '(')
	++parens;
      
      else if (c == ')')
	--parens;
      
      else if (c == '[')
	++brackets;
      
      else if (c == ']')
	--brackets;
      
      else if (c == '{')
	++braces;
      
      else if (c == '}')
	--braces;
      
      else if ((c == '\'') || (c == '"'))
       	{
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
	}
      if ((brackets < 0) || (braces < 0) || (parens < 0))
	{
	  printf("Error!\n");
	  break;
	}
    }
    if (brackets > 0)
      printf("Unclosed brackets: [ \n");
    else if (brackets < 0)
      printf("Unopened brackets: ] \n");

    if (parens > 0)
      printf("Unclosed parentheses: ( \n");
    else if (parens < 0)
      printf("Unopened parentheses: ) \n");

    if (braces > 0)
      printf("Unclosed braces: { \n");
    else if (braces < 0)
      printf("Unopened braces: } \n");

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
