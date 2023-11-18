#include "../test-utils/lib.h"
#include "lib.h"
#include <assert.h>

void test_differentiate(void) {
  size_t test_values_len = 6;
  double test_values[6] = {0, 0.000001234, 1, 2, 1000, -1234987};

  for (size_t i = 0; i < test_values_len; ++i) {
    printf("for input %f expected %f, got %f\n", test_values[i],
           differentiate(test_values[i]), test_values[i] * 2);
  }
}

int main(void) { test_differentiate(); }
