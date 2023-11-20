#include <stddef.h>

size_t partition(float arr[], size_t start_idx, size_t end_idx) {
  size_t partition_idx = start_idx;
  float pivot_value = arr[end_idx - 1];
  for (size_t i = start_idx; i < end_idx - 1; ++i) {
    if (arr[i] <= pivot_value) {
      float swap = arr[i];
      arr[i] = arr[partition_idx];
      arr[partition_idx] = swap;
      partition_idx++;
    }
  }
  arr[end_idx - 1] = arr[partition_idx];
  arr[partition_idx] = pivot_value;
  return partition_idx;
}

void quicksort_inner(float arr[], size_t start_idx, size_t end_idx) {
  size_t len = end_idx - start_idx;
  if (len < 2)
    return;
  size_t partition_idx = partition(arr, start_idx, end_idx);
  quicksort_inner(arr, start_idx, partition_idx);
  quicksort_inner(arr, partition_idx + 1, end_idx);
}

void quicksort(float arr[], size_t len) { quicksort_inner(arr, 0, len); }
