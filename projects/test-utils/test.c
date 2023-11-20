#include "lib.h"
#include <assert.h>

void test_arrs_are_equal(void) {
  float arrA[] = {1, 2, 3};
  float arrB[] = {1, 2, 3};
  float arrC[] = {3, 2, 1};
  assert(arrs_are_equal(arrA, arrB, 3, 3));
  assert(!arrs_are_equal(arrA, arrC, 3, 3));
}

int main(void) { test_arrs_are_equal(); }
