#include "test.h"

START_TEST(s21_create_matrix_1) {
  // success creation
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  // failure null pointer
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  // failure incorrect rows/columns
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  // failure incorrect rows/columns
  ck_assert_int_eq(s21_create_matrix(5, 0, NULL), INCORRECT_MATRIX);
}
END_TEST

Suite *test_suite_create(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Test Create");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_create_matrix_1);
  tcase_add_test(tc_core, s21_create_matrix_2);
  tcase_add_test(tc_core, s21_create_matrix_3);
  tcase_add_test(tc_core, s21_create_matrix_4);
  suite_add_tcase(s, tc_core);

  return s;
}
int test_create() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = test_suite_create();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}