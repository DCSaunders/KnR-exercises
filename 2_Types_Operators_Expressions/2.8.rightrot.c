# include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
  printf("%u\n", rightrot((unsigned)8, 2));
  return 0;
}


unsigned rightrot(unsigned x, int n)
{
  return (x >> n) & ~(0 >> n);
}
