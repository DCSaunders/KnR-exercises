#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>

int main()
{
  
  printf("Unsigned char printed: %d to %u\n", 0, UCHAR_MAX);
  printf("Unsigned char calculated: %d to %.0f\n", 0, pow(2, CHAR_BIT) - 1);
  printf("Signed char printed: %d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("Signed char calculated: %.0f, %.0f\n\n", -pow(2, CHAR_BIT - 1), pow(2, CHAR_BIT - 1) - 1);

  printf("Unsigned int printed: %d to %u\n", 0, UINT_MAX);
  printf("Signed int printed: %d to %d\n\n", INT_MIN, INT_MAX);

  printf("Unsigned short printed: %d, %d \n", 0, USHRT_MAX);
  printf("Signed short printed: %d, %d\n\n", SHRT_MIN, SHRT_MAX);

  printf("Unsigned long printed: %d, %lu\n", 0, ULONG_MAX);
  printf("Signed long printed: %ld, %ld\n\n", LONG_MIN, LONG_MAX);


  printf("Float printed: %.10e to %.10e\n", FLT_MIN, FLT_MAX);
  printf("Float calculated: %.10e to %.10e\n",  pow(FLT_RADIX, FLT_MIN_EXP) / 2, pow(FLT_RADIX, FLT_MAX_EXP));
  printf("Double printed: %.10e to %.10e\n", DBL_MIN, DBL_MAX);
  return 0;
}
