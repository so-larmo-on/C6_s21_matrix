

#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (result == NULL || rows < 1 ||
      columns < 1) {  // проверка на NULL и кол-во стр. и стол. больше 0
    error = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(
        rows + rows * columns, sizeof(double));  // выделение памяти под матрицу
    if (result->matrix != NULL) {
      double *start = (double *)(result->matrix + rows);
      int iteration_limit = rows <= columns ? columns : rows;
      for (int i = 0; i < iteration_limit; i++) {
        result->matrix[i] = start + i * columns;
      }
    }
  }
  return error;
}
