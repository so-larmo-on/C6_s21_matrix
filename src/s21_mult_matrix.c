#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;

  if (A == NULL || B == NULL || !is_matrix_valid(*A) || !is_matrix_valid(*B) ||
      result == NULL) {  // проверка на NULL; действительность; и NULL в result
    err = INCORRECT_MATRIX;

  } else if (A->columns != B->rows || s21_isinf(*A) ||
             s21_isinf(*B)) {  // проверка на совпадение размеров матриц A и B;
    // на содержание INFINITY хотя бы в одной из них
    err = ERROR;

  } else {
    s21_create_matrix(A->rows, B->columns,
                      result);  // создание матрицы result с кол-во строк A и
                                // кол-во столбцов B
    for (int i = 0; i < B->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[j][i] +=
              A->matrix[j][k] *
              B->matrix[k][i];  // умножение матриц A и B, с использованием
                                // тройного цикла
        }
      }
    }
  }
  return err;
}