#include <stdio.h>
#include <string.h>

void pi_digits(int n) {
  char result[n + 2];
  int len = ((10 * n) / 3) + 1;
  long i, j, k, q, x, nines, predigit;
  long a[len + 1];

  for (j = 1; j <= len; j++) {
    a[j] = 2;
  }
  nines = 0;
  predigit = 0;

  for (j = 1; j <= n; j++) {
    q = 0;
    for (i = len; i >= 1; i--) {
      x = 10 * a[i] + q * i;
      a[i] = x % (2 * i - 1);
      q = x / (2 * i - 1);
    }
    a[1] = q % 10;
    q = q / 10;

    if (q == 9) {
      nines = nines + 1;
    } else if (q == 10) {
      char buffer[100] = {0};
      sprintf(buffer, "%ld", predigit + 1);
      strcat(result, buffer);
      for (k = 1; k <= nines; k++) {
        strcat(result, "0");
      }
      predigit = 0;
      nines = 0;
    } else {
      char buffer[100] = {0};
      sprintf(buffer, "%ld", predigit);
      strcat(result, buffer);
      predigit = q;
      if (nines != 0) {
        for (k = 1; k <= nines; k++) {
          strcat(result, "9");
        }
        nines = 0;
      }
    }
  }
  char buffer[100] = {0};
  sprintf(buffer, "%ld", predigit);
  strcat(result, buffer);
  printf("3.%s\n", result + 2);
}
