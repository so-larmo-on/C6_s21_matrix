#include <math.h>

#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  matrix_t minor;  // временная мат. minor которая будет исп-ся для выч-ия
                   // миноров
  if (A == NULL || !is_matrix_valid(*A) ||
      result == NULL) {  // проверка на NULL; действительность; и NULL в result
    err = INCORRECT_MATRIX;
  } else if (!is_matrix_squared(*A) ||
             s21_isinf(
                 *A)) {  // проверка на квадр. мат. А, и бесконеч. значения
    err = ERROR;
  } else if (A->rows == 1) {  // размерность мат. А 1x1
    s21_create_matrix(A->rows, A->columns,
                      result);  // создание мат. result такой же размерности
    result->matrix[0][0] = 0;  // присвоение эл-ту значения 0
  } else {
    s21_create_matrix(A->rows, A->columns,
                      result);  // создание мат. result размерности мат. А
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
        make_minor(*A, i, j, &minor);  // создание минора для каждого эл-та
        double det = 0;
        s21_determinant(&minor, &det);  // выч-ие опред-ля для каждого минора
        result->matrix[i][j] = det * pow(-1, i + j);

        s21_remove_matrix(&minor);  // удаление временной матрицы
      }
    }
  }
  return err;
}
