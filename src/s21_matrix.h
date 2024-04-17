#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define ERROR 2
#define s21_EPS 1e-6

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// создание матрицы:
int s21_create_matrix(int rows, int columns, matrix_t *result);
// очистка и уничтожение:
void s21_remove_matrix(matrix_t *A);
// сравнение:
int s21_eq_matrix(matrix_t *A, matrix_t *B);
// сложение:
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// вычитание:
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// умножение на число:
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
// умножение:
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// транспонирование:
int s21_transpose(matrix_t *A, matrix_t *result);
// вычисление матрицы алгебраических дополнений:
int s21_calc_complements(matrix_t *A, matrix_t *result);
// вычисление определителя:
int s21_determinant(matrix_t *A, double *result);
// поиск обратной матрицы:
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
// проверка на дейстаительность матрицы:
int is_matrix_valid(matrix_t A);
// проверка на совпадение размеров матриц:
int is_same_size(matrix_t A, matrix_t B);
// создание минора матрицы A, исключая указанную строку и столбец:
void make_minor(matrix_t A, int row, int column, matrix_t *result);
// проверка на содержание в матрице А INFINITY
int s21_isinf(matrix_t A);
void make_full_matrix(matrix_t *A, double start, double step);
// проверка на квадратность матрицы:
int is_matrix_squared(matrix_t A);
void s21_init_matrix(double number, matrix_t *A);

#endif