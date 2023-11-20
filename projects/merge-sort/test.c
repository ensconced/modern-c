#include "../test-utils/lib.h"
#include "lib.h"
#include <assert.h>
#include <stdbool.h>

void test_merge_halves(void) {
  float arr[] = {0, 3, 5, 1, 2, 4};
  float result[6];
  float expected_result[] = {0, 1, 2, 3, 4, 5};
  merge(arr, 0, 3, 6, result);
  assert(arrs_are_equal(result, expected_result, 6, 6));
}

void test_merge_quarters(void) {
  float arr[] = {1, 2, 3, 4, 5, 7, 6, 8};
  float result[8] = {0};
  float expected_result[] = {0, 0, 0, 0, 5, 6, 7, 8};
  merge(arr, 4, 6, 8, result);
  assert(arrs_are_equal(result, expected_result, 8, 8));
}

void test_merge_sort(void) {
  float arr[] = {3, 8, 2, 7, 4, 6, 9, 1, 5};
  merge_sort(arr, 9);
  float expected_result[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  assert(arrs_are_equal(arr, expected_result, 9, 9));
}

void test_empty_merge_sort(void) {
  float arr[] = {0};
  merge_sort(arr, 0);
  float expected_result[] = {0};
  assert(arrs_are_equal(arr, expected_result, 0, 0));
}

int main(void) {
  test_merge_halves();
  test_merge_quarters();
  test_merge_sort();
  test_empty_merge_sort();
}
