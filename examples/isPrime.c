#include<stdio.h>
#include<stdlib.h>

int isPrime(int N)
{
  if(N <= 1)
    {
       printf("%d is not a prime\n", N);
       return 0;
    }
  for(int i = 2; i < N; i++)
    {
      if (N % i == 0)
	{
	  printf("%d is not a prime\n", N);
	  return 0;
	}
    }
  printf("%d is a prime\n", N);
  return 1;
}


int main(void)
{
  isPrime(4);
  return 0;
}
