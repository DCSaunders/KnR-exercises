# include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

int main()
{
  printf("%u\n", setbits((unsigned)12, 3, 2, (unsigned)57));
  return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned right_most_n_ones = ~(~0 << n);
  unsigned n_digits = (p + 1 - n);
  return (x & ~(right_most_n_ones << n_digits)) | (y & (right_most_n_ones << n_digits));
}

unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}
