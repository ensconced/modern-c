#include <stdbool.h>
#include <stddef.h>
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

void log_array(float arr[], size_t len) {
  for (size_t i = 0; i < len; ++i) {
    printf("%f, ", arr[i]);
  }
}
