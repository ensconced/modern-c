#include <stddef.h>

void multiply(float matrix_a[][], float matrix_b[][], size_t a_rows,
              size_t a_cols, size_t b_rows, size_t b_cols, float result[][]) {
  for (size_t a_row_idx = 0; a_row_idx < a_rows; ++a_row_idx) {
    float row[] = matrix_a[a_row_idx];
    float val = 0;
    for (size_t b_col_idx = 0; b_col_idx < b_cols; ++b_col_idx) {
      // val +=
    }
  }
}
