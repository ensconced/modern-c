#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool arrs_are_equal(float a[], float b[], size_t a_len, size_t b_len) {
  if (a_len != b_len)
    return false;
  for (size_t i = 0; i < a_len; ++i) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

void log_array(float arr[], size_t arr_len) {
  for (size_t i = 0; i < arr_len; ++i) {
    printf("%f, ", arr[i]);
  }
}

void merge(float a[], float b[], size_t a_len, size_t b_len, float result[]) {
  size_t taken_from_a = 0;
  size_t taken_from_b = 0;
  size_t result_len = a_len + b_len;
  for (size_t i = 0; i < result_len; ++i) {
    if (taken_from_a == a_len) {
      result[i] = b[taken_from_b++];
    } else if (taken_from_b == b_len) {
      result[i] = a[taken_from_a++];
    } else if (a[taken_from_a] < b[taken_from_b]) {
      result[i] = a[taken_from_a++];
    } else {
      result[i] = b[taken_from_b++];
    }
  }
}

void test_merge(void) {
  float a[] = {0, 3, 5};
  float b[] = {1, 2, 4};
  float result[6];
  float expected_result[] = {0, 1, 2, 3, 4, 5};
  merge(a, b, 3, 3, result);
  assert(arrs_are_equal(result, expected_result, 6, 6));
}

int main(void) { test_merge(); }
