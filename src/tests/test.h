#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#define OK 0
#define ERROR_INIT 1
#define ERROR_CALC 2
#define MAX_DOUBLE 1.79769e+308
#define MIN_DOUBLE 2.22507e-308

void s21_init_matrix(double number, matrix_t *A);
int test_calc();
int test_create();
int test_det();
int test_eq();
int test_inv();
int test_mat();
int test_num();
int test_rem();
int test_sub();
int test_sum();
int test_tran();

#endif