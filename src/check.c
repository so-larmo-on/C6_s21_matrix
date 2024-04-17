
#include "tests/test.h"

int main() {
  int no_failed = 0;
  no_failed |= test_calc();
  no_failed |= test_create();
  no_failed |= test_det();
  no_failed |= test_eq();
  no_failed |= test_inv();
  no_failed |= test_mat();
  no_failed |= test_num();
  no_failed |= test_rem();
  no_failed |= test_sub();
  no_failed |= test_sum();
  no_failed |= test_tran();

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}