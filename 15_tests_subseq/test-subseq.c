#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n);

int main()
{

int array1[] = {1};
int array2[] = {-5, -4, -3, -2, -1, 0};
int array3[] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8};
int array4[] = {};
int array5[] = {1, 3, 5, 4, 5, 9, 15, 16, 19, 20};

  if(maxSeq(array2, 6) != 6)
    {
      printf("Failed on -5, -4, -3, -2, -1, 0\n");
  exit (EXIT_FAILURE);
    }
  if(maxSeq(array3, 10) != 6)
    {
      printf("Failed on 1, 2, 3, 3, 3, 4, 5, 6, 7, 8\n");
  exit (EXIT_FAILURE);
}
  if(maxSeq(array4, 0) != 0)
    {
      printf("Failed on {}\n");
  exit (EXIT_FAILURE);
}
  if(maxSeq(array1, 1) != 1)
    {
      printf("Failed on 1\n");
  exit (EXIT_FAILURE);
}
  if(maxSeq(array5, 10) == 7)
    {
      printf("Passed on 1, 3, 5, 4, 5, 9, 15, 16, 19, 20\n");
  exit (EXIT_SUCCESS);
}
}
