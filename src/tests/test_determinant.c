#include "test.h"

START_TEST(s21_determinant_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&A, &det), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_2) {
  // failure with non-square matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 2, &A);
  make_full_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  // success with task reference values
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  make_full_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  // success with 2x2 matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  make_full_matrix(&A, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -18);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  // success with 1x1 matrix
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(s21_determinant_6) {
  matrix_t a;
  double result = 0;
  int return_code = 0;
  s21_create_matrix(3, 3, &a);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i * 3 + j + 1;
    }
  }
  return_code = s21_determinant(&a, &result);
  ck_assert_int_eq(return_code, 0);
  ck_assert_double_eq(result, 0);
  a.rows = 2;
  return_code = s21_determinant(&a, &result);
  ck_assert_int_eq(return_code, 2);
  a.rows = 3;
  return_code = s21_determinant(NULL, &result);
  ck_assert_int_eq(return_code, 1);
  return_code = s21_determinant(&a, NULL);
  ck_assert_int_eq(return_code, 1);
  s21_remove_matrix(&a);
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 1;
  return_code = s21_determinant(&a, &result);
  s21_remove_matrix(&a);
  ck_assert_int_eq(return_code, 0);
  ck_assert_double_eq(result, 1);
}
END_TEST
START_TEST(s21_determinant_01) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};

  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, ERROR_INIT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_02) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);

  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_03) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_04) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 4000.87;
  A.matrix[0][1] = 454.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 1.897;
  A.matrix[1][2] = 3.0;
  A.matrix[2][0] = 0.000087;
  A.matrix[2][1] = 2.5668;
  A.matrix[2][2] = 1.0;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -24105.996724156);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_05) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -677700.0;
  A.matrix[0][1] = 654.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -0.00001;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -1301.223);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_06) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(8, 8, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_s21_determinant1) {
  matrix_t matrix = {0};
  s21_create_matrix(3, 3, &matrix);
  int count = 1;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = count++;
    }
  }
  matrix.matrix[2][2] = 10;
  double res = 0;
  int ret = s21_determinant(&matrix, &res);
  ck_assert_int_eq(res, -3);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *test_suite_det(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Test Det");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_determinant_1);
  tcase_add_test(tc_core, s21_determinant_2);
  tcase_add_test(tc_core, s21_determinant_3);
  tcase_add_test(tc_core, s21_determinant_4);
  tcase_add_test(tc_core, s21_determinant_5);
  tcase_add_test(tc_core, s21_determinant_6);
  tcase_add_test(tc_core, s21_determinant_01);
  tcase_add_test(tc_core, s21_determinant_02);
  tcase_add_test(tc_core, s21_determinant_03);
  tcase_add_test(tc_core, s21_determinant_04);
  tcase_add_test(tc_core, s21_determinant_05);
  tcase_add_test(tc_core, s21_determinant_06);
  tcase_add_test(tc_core, test_s21_determinant1);
  suite_add_tcase(s, tc_core);

  return s;
}
int test_det() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = test_suite_det();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}