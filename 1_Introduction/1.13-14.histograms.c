#include <stdio.h>

#define WLENGTHS   20 /*arbitrary upper limit on word length */
#define CLENGTHS   26 /*count lower-case alphabetical chars*/
#define IN         1
#define OUT        0
#define HORIZONTAL 0

/* Count digits, white space, others */
int main()
{
  int c, i, j, state, wlength, max_wlfreq, max_lfreq;
  int nwords[WLENGTHS];
  int nletters[CLENGTHS];
  state = OUT;
  wlength, max_wlfreq, max_lfreq = 0;
  for (i = 0; i<CLENGTHS; ++i)
    {
      nletters[i] = 0;
    }
  
  for (i = 0; i<WLENGTHS; ++i)
    {
      nwords[i] = 0;
    }
  
  
    while((c = getchar()) != EOF)
    {
    if(c >= 'a' && c <= 'z')
      {
	if (state == OUT)
	    state = IN;
      ++nletters[c - 'a'];
      if (max_lfreq < nletters[c - 'a'])
			    max_lfreq = nletters[c - 'a'];
      ++wlength;
      }
    else if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
      {
      state = OUT;
      if (wlength < WLENGTHS)
	++nwords[wlength];
      if (max_wlfreq < nwords[wlength])
	max_wlfreq = nwords[wlength];
      wlength = 0;
      }
    }

    if (HORIZONTAL == 1)
      {
  printf("word lengths =");
  for (i = 0; i < WLENGTHS; ++i)
    {
      printf("\n %d", i + 1);
      for (j = 0; j < nwords[i]; ++j)
	printf("#");
    }
 printf("\nletters ="); 
 for (i = 0; i < CLENGTHS; ++i)
    {
      printf("\n %c", i + 'a');
      for (j = 0; j < nletters[i]; ++j)
	printf("#");
    }
      }
  else{
  printf("word lengths =\n");
  for (j = max_wlfreq; j>=0; --j)
    {
  for (i = 1; i < WLENGTHS; ++i)
    if (j <= nwords[i])
      {
	if (j > 0)
	  printf(" # ");
	else
	  printf(" %d ", i);
      }
    else
      {
      printf("   ");
      }
  printf("\n");
    }

  printf("\nletters =\n");
  for (j = max_lfreq; j>=0; --j)
    {
  for (i = 0; i < CLENGTHS; ++i)
    if (j <= nletters[i])
      {
	if (j > 0)
	  printf(" # ");
	else
	  printf(" %c ", i + 'a');
      }
    else
      {
      printf("   ");
      }
  printf("\n");
    }

  }
}
