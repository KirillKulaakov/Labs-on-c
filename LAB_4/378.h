#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>
#include <cstdio>
#include <iomanip>


#ifndef HEADER

#define HEADER

int continue_programm(int* exit);
int choose_form_input_output();
int choose_user(int choose);
int result(int inp, int outp, int n);
void clear_memory(float** ptr, int n);
int matrix_initialization(float** matrix, float* numbers, int n);
int enter_numbers_from_console(float* numbers, float** matrix, int n);
int enter_numbers_from_file(float* numbers, float** matrix, int n);
void input_matrix(float** matrix, float* numbers, int n);
void output_matrix_to_console(float** matrix, int n);
int output_matrix_to_file(float** matrix, int n);
void clear_all(float** matrix, float* numbers, int n);
int check_invalide();

#endif


