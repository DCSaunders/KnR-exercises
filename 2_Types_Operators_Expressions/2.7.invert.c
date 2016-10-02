# include <stdio.h>

unsigned invert(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);

int main()
{
  printf("%u\n", invert((unsigned)8, 3, 5));
  return 0;
}


unsigned invert(unsigned x, int p, int n)
{
  unsigned mask = ((~0 << p) ^ (~0 << n + p));
  return (x ^ mask);
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}
