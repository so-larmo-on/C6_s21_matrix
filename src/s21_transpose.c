#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (A == NULL || !is_matrix_valid(*A) ||
      result == NULL) {  // проверка на NULL; действительность; и NULL в result
    err = INCORRECT_MATRIX;
  }
  if (!err) {
    s21_create_matrix(A->columns, A->rows,
                      result);  // создание новой матрицы result с размерами,
                                // обратными размерам матрицы A
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] =
            A->matrix[j][i];  // копирование эл-ов из мат. A в соои-щие позиции
                              // мат. result с учетом транспонирования
      }
    }
  }
  return err;
}