#include <stdio.h>

void merge(float src[], size_t start_idx, size_t midpoint, size_t end_idx,
           float target[]) {
  size_t a_next_idx = start_idx;
  size_t b_next_idx = midpoint;
  size_t result_len = end_idx - start_idx;
  for (size_t i = 0; i < result_len; ++i) {
    size_t target_idx = i + start_idx;
    if (a_next_idx == midpoint) {
      target[target_idx] = src[b_next_idx++];
    } else if (b_next_idx == end_idx) {
      target[target_idx] = src[a_next_idx++];
    } else if (src[a_next_idx] < src[b_next_idx]) {
      target[target_idx] = src[a_next_idx++];
    } else {
      target[target_idx] = src[b_next_idx++];
    }
  }
}

void copy_arr(float src[], float target[], size_t len) {
  for (size_t i = 0; i < len; ++i) {
    target[i] = src[i];
  }
}

void merge_sort_inner(float src[], float target[], size_t start_idx,
                      size_t end_idx) {
  size_t len = end_idx - start_idx;
  size_t midpoint = start_idx + len / 2;
  size_t lhs_len = midpoint - start_idx;
  size_t rhs_len = end_idx - midpoint;
  if (lhs_len > 1) {
    merge_sort_inner(target, src, start_idx, midpoint);
  }
  if (rhs_len > 1) {
    merge_sort_inner(target, src, midpoint, end_idx);
  }
  merge(src, start_idx, midpoint, end_idx, target);
}

void merge_sort(float arr[], size_t len) {
  float work_arr[len];
  copy_arr(arr, work_arr, len);
  merge_sort_inner(work_arr, arr, 0, len);
}
