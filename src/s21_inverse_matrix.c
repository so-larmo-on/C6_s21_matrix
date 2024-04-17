#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;
  double det = 0;
  if (A == NULL || !is_matrix_valid(*A) ||
      result == NULL) {  // проверка на NULL; действительность; и NULL в result
    err = INCORRECT_MATRIX;
  }
  if (!err &&
      ((!is_matrix_squared(*A)) ||
       s21_isinf(*A))) {  // проверка на квадр. мат. А, и бесконеч. значения
    err = ERROR;
  }
  if (!err) {
    matrix_t calc_complements;  // создание временной мат. для выч-ия алг. доп.
    s21_determinant(A, &det);   // вычисление опр-ля мат. А
    if ((fabs(det - 0) <= 1.000000e-06)) {
      err = ERROR;
    }

    if (!err && A->rows == 1) {  // размерность мат. А 1x1
      s21_create_matrix(
          A->rows, A->columns,
          result);  // создание мат. result размерности обратной мат. А
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }

    if (!err && A->rows > 1) {
      s21_calc_complements(A, &calc_complements);
      //     printf("calc\n");
      //     for (int i = 0; i < calc_complements.rows; i++) {
      //     for (int j = 0; j < calc_complements.columns; j++) {
      //       printf("%f ", calc_complements.matrix[i][j]);
      //     }
      //     printf("\n");
      // }
      // printf("trans\n");
      s21_transpose(&calc_complements, result);
      // for (int i = 0; i < result->rows; i++) {
      // for (int j = 0; j < result->columns; j++) {
      //   printf("%f ", result->matrix[i][j]);
      // }
      // printf("\n");
      // }
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] /=
              det;  // каждый эл-т мат. result делится на определитнль
        }
      }

      // printf("\n");
      s21_remove_matrix(&calc_complements);  // удаление временной матрицы
    }
  }
  return err;
}