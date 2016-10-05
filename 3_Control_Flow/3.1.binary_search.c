#include <stdio.h>
#define LENGTH 4

/*Find x in v[0] to v[n-1]*/
int binsearch_test_in(int x, int v[], int n);
int binsearch_test_out(int x, int v[], int n);

int main()
{
  int v[LENGTH] = {0, 2, 5, 6};
  printf("position %d\n", binsearch_test_out(2, v, LENGTH)); 
  return 0;
}

//Rewrite
int binsearch_test_out(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  mid = high / 2;
  while ((low <= high) && (x!=v[mid]))
    {
      if (x > v[mid])
	{
	low = mid + 1;
    }
      else
	{
	high = mid - 1;
    }
      mid = (low + high)/2;
    }
  if (x == v[mid])
    {
    return mid;
    }
  else
    {
    return -1;
    }
}


//Original
int binsearch_test_in(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high)
    {
      mid = (low + high)/2;
      if (x < v[mid])
	high = mid - 1;
      else if (x > v[mid])
	low = mid + 1;
      else
	return mid;
    }
  return -1;
}
