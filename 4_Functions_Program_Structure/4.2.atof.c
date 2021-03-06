#include <ctype.h>
#include <stdio.h>
#include <math.h>

double atof(char s[]);
int getline_new(char line[], int lim);

#define MAXLINE 100

int main()
{
  double sum;
  char line[MAXLINE];
  sum = 0;
  while (getline_new(line, MAXLINE) > 0)
    printf("\t%g\n", sum+= atof(line));

  return 0;
}


int getline_new(char line[], int lim)
{
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
      line[i++] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

double atof(char s[])
{
  double val, dp, exponent, expdp;
  int i, sign;
  for (i = 0; isspace(s[i]); i++);
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    {
      val *= 10;
      val += (s[i] - '0');
    }
  if (s[i] == '.')
    i++;
  for (dp = 1.0; isdigit(s[i]); i++)
    {
      val *= 10;
      val += (s[i] - '0');
      dp *= 10.0;
    }
  if (s[i] == 'e' || s[i] == 'E')
    {
      i++;
        if (s[i] == '+' || s[i] == '-')
    i++;
  for (exponent = 0.0; isdigit(s[i]); i++)
    {
      exponent *= 10;
      exponent += (s[i] - '0');
    }
  if (s[i] == '.')
    i++;
  for (expdp = 1.0; isdigit(s[i]); i++)
    {
      exponent *= 10;
      exponent += (s[i] - '0');
      expdp *= 10.0;
    }
  exponent = exponent / expdp;
    }
  return sign * (val / dp) * pow(10.0, exponent);

}
