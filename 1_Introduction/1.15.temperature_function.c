#include <stdio.h>

#define LOWER      0      /* lower temperature limit */
#define UPPER      300    /* upper temperature limit */
#define STEP       20     /* temperature step */
#define TO_FAHR    0
#define TO_CELSIUS 1
float convert(int conversion, float in_temp);

float convert(int conversion, float in_temp)
{
  float converted_temp;
  if (conversion == TO_FAHR)
    converted_temp = (9.0 * in_temp / 5.0) + 32.0;
  else if (conversion == TO_CELSIUS)
    converted_temp = (5.0 / 9.0) * (in_temp - 32.0);
  return converted_temp;
}


/* Prints the Fahrenheit-Celsius conversion table */
int main()
{
  float fahr, celsius;

  printf("Fahrenheit Celsius\n");
  for(fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
      printf("%7.1f %9.1f\n", fahr, convert(TO_CELSIUS, fahr));
    }

  printf("Celsius Fahrenheit\n");
  for(celsius = UPPER; celsius >= LOWER; celsius -= STEP)
    {
      printf("%5.1f %8.1f\n", celsius, convert(TO_FAHR, celsius));
    }
}
