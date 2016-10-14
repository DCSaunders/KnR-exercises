#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

/*The original itoa function does not handle the largest negative number. This is because the number is first made positive (if negative) by multiplying by sign. |largest possible negative int| > |largest positive int|, so this would fail according to the values in limits.h (-2147483648)*/

void itoa(int n, char s[]);
void itoa_pad(int n, char s[], int w);
void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
  char s[MAXLEN];
  int n = 31;
  itoa_pad(n, s, 14);
  printf("%s\n", s);
  return 0;
}

void itoa(int n, char s[])
{
  int i, sign;
  sign = (n < 0) ? -1 : 1;
  i = 0;
  do {
    s[i++] = sign * (n % 10) + '0';
  } while (sign * (n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void itoa_pad(int n, char s[], int w)
{
  int i, sign;
  sign = (n < 0) ? -1 : 1;
  i = 0;
  do {
    s[i++] = sign * (n % 10) + '0';
  } while (sign * (n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
 while (i < w)
   {
     s[i++] = ' ';
   }
  s[i] = '\0';
  reverse(s);
}


void itob(int n, char s[], int b)
{
  int i, sign, digit;
  sign = (n < 0) ? -1 : 1;
  i = 0;
  do {
    digit = sign * (n % b);
    digit += (digit > 9)? ('A' - 10) : '0'; 
    s[i++] = digit;
  } while (sign * (n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[])
{
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}
