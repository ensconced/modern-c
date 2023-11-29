#include <stddef.h>

void multiply(float matrix_a[], float matrix_b[], size_t a_rows, size_t a_cols,
              size_t b_cols, float result[]) {
  for (size_t result_row_idx = 0; result_row_idx < a_rows; ++result_row_idx) {
    for (size_t result_col_idx = 0; result_col_idx < b_cols; ++result_col_idx) {
      float val = 0;
      for (size_t i = 0; i < a_cols; ++i) {
        val += matrix_a[result_row_idx * a_cols + i] *
               matrix_b[i * b_cols + result_col_idx];
      }
      result[result_row_idx * a_rows + result_col_idx] = val;
    }
  }
}
