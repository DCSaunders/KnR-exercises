#include <stdio.h>

#define LOWER 0      /* lower temperature limit */
#define UPPER 300    /* upper temperature limit */
#define STEP  20     /* temperature step */

/* Prints the Fahrenheit-Celsius conversion table */
int main()
{
  float fahr, celsius;

  printf("Fahrenheit Celsius\n");
  for(fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
      celsius = (5.0 / 9.0) * (fahr - 32.0);
      printf("%7.1f %9.1f\n", fahr, celsius);
    }

  printf("Celsius Fahrenheit\n");
  for(celsius = UPPER; celsius >= LOWER; celsius -= STEP)
    {
      fahr = (9.0 * celsius / 5.0) + 32.0;
      printf("%5.1f %8.1f\n", celsius, fahr);
    }
}
