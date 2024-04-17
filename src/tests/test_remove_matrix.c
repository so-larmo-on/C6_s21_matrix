#include "test.h"

START_TEST(s21_remove_matrix_1) {
  // success remove
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  // failure handle null pointer
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  // failure handle INCORRECT_MATRIX structure
  matrix_t A = {};
  s21_create_matrix(0, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

Suite *test_suite_rem(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Test Rem");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_remove_matrix_1);
  tcase_add_test(tc_core, s21_remove_matrix_2);
  tcase_add_test(tc_core, s21_remove_matrix_3);

  suite_add_tcase(s, tc_core);

  return s;
}
int test_rem() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = test_suite_rem();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}