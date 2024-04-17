#include "s21_matrix.h"

int is_same_size(matrix_t A, matrix_t B) {
  int result = SUCCESS;
  if (A.rows != B.rows || A.columns != B.columns) {
    result = FAILURE;
  }
  return result;
}

int is_matrix_valid(matrix_t A) {
  int error = 1;

  if (A.matrix == NULL) {
    error = 0;
  } else if (A.rows < 1 || A.columns < 1) {
    error = 0;
  }
  return error;
}
void make_minor(matrix_t A, int row, int column, matrix_t *result) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (i != row && j != column) {
        result->matrix[i - (i > row)][j - (j > column)] = A.matrix[i][j];
      }
    }
  }
}
int s21_isinf(matrix_t A) {
  int err = OK;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (A.matrix[i][j] == INFINITY) {
        err = ERROR;
      }
    }
  }
  return err;
}

void make_full_matrix(matrix_t *A, double start, double step) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = start;
      start += step;
    }
  }
}
int is_matrix_squared(matrix_t A) {
  int status = 1;
  if (A.columns != A.rows) {
    status = 0;
  }
  return status;
}
void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}