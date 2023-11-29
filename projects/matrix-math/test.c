#include "./lib.h"
#include <assert.h>

void test_multiply(void) {
  float a[] = {1, 2, 3, 4, 5, 6};
  float b[] = {7, 8, 9, 10, 11, 12};
  float expected_result[] = {58, 64, 139, 154};
  float result[4] = {0};
  multiply(a, b, 2, 3, 2, result);

  for (size_t i = 0; i < 4; ++i) {
    assert(result[i] == expected_result[i]);
  }
}

int main(void) { test_multiply(); }
