#include "../test-utils/lib.h"
#include "lib.h"
#include <assert.h>

void test_quicksort(void) {
  float arr[] = {3,  4,  30, 9,  65, 73, 59, 86, 85, 24,
                 76, 28, 36, 58, 27, 81, 13, 94, 6,  89};
  quicksort(arr, 20);
  float expected_result[] = {3,  4,  6,  9,  13, 24, 27, 28, 30, 36,
                             58, 59, 65, 73, 76, 81, 85, 86, 89, 94};
  assert(arrs_are_equal(arr, expected_result, 20, 20));
}

int main(void) { test_quicksort(); }
