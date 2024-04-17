#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (A == NULL || !is_matrix_valid(*A) ||
      result == NULL) {  // проверка на NULL; действительность; и NULL в result
    err = INCORRECT_MATRIX;
  } else if (!is_matrix_squared(*A) ||
             s21_isinf(*A)) {  // если мат. A не является квадр-ой или содержит
                               // беск. значения
    err = ERROR;
  } else {
    if (A->rows == 1) {  // размерность мат. А 1x1
      *result = A->matrix[0][0];  // определитель = един-му эл-ту матрицы

    } else if (A->rows == 2) {  // размерность мат. А 2x2
      *result =
          A->matrix[0][0] * A->matrix[1][1] -
          A->matrix[0][1] * A->matrix[1][0];  // определитель вычисляется
                                              // по формуле для матрицы 2x2

    } else {  // разложение опр-ля по 1-ой строке с исп. миноров
      int sign = 1;
      for (int i = 0; i < A->columns; i++) {
        double minor_determinant = 0;
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        make_minor(*A, 0, i, &minor);  // создание миноров
        s21_determinant(&minor, &minor_determinant);  // вычисления опр-ей
                                                      // миноров
        *result += sign * A->matrix[0][i] * minor_determinant;
        sign *= -1;
        s21_remove_matrix(&minor);
      }
    }
  }

  return err;
}