#include <stdio.h>

int main(void)
{
  double A[5] = {
      9.0,
      2.9,
      3.E+25,
      .00007,
  };

  for (size_t i = 0; i < 5; ++i)
  {
    printf("element %zu is %g, \tits square is %g\n", i, A[i], A[i] * A[i]);
  }

  return 0;
}
