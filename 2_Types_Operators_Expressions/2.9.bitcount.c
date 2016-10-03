# include <stdio.h>

int bitcount(unsigned x);

int main()
{
  printf("%u\n", bitcount((unsigned)8));
  return 0;
}


int bitcount(unsigned x)
{
  int count;
  for (count = 0; x != 0; x &= x-1)
    ++count;
  return count;
}
