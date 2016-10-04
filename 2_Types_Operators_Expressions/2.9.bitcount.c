#include <stdio.h>

/*
Explanation:
2's complement converts a positive bit representation into negative by inverting the bit representation (all 0s become 1s and vice versa) , then adding 1. So x - 1 is equivalent to x + 11111111

If the rightmost bit of x is 1, the rightmost bit of x - 1 will be 0 (because 1 + 1 = 0 in binary) and x & (x-1) will have rightmost bit 0, because 1&0 = 0.

If the rightmost bit of x is 0, the rightmost bit of x - 1 will be 1 (because 0 + 1 = 1) and x & (x-1) will have rightmost bit 0, because 1&0 = 0.

So x&=(x-1) always sets the rightmost bit of x to 0 in 2's complement.

In fact, x&=(x-1) will always set the rightmost 1 to 0 and any run of 0s before that to 1. Only one on-bit (1) will be affected on each x&=(x-1), so this can be done n times before x == 0, where n is the number of on bits in x originally.

Let x = 0100101
Then x & (x-1) = 
   0100101 & (0100101 + 11111111) = 
   0100101 & 01001000 =
   0100100
(one on-bit has been removed).
   
*/

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
