#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err = OK;
  if (!is_matrix_valid(*A) ||
      result == NULL) {  // проверка на NULL; действительность
    err = INCORRECT_MATRIX;
  }
  if ((s21_isinf(*A)) ||
      number == INFINITY) {  // проверка на содержание INFINITY в матрице А; и
    // INFINITY в number
    err = ERROR;
  }
  if (!err) {
    s21_create_matrix(
        A->rows, A->columns,
        result);  // создание новой матрицы result с размерами матрицы A
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] =
            A->matrix[i][j] *
            number;  // создание новой матрицы result с размерами матрицы A
      }
    }
  }
  return err;
}