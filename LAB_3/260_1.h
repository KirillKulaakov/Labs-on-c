#include <iostream>
#include <limits>
#include <fstream>

#ifndef HEADER_1

#define HEADER_1

int choose_user(int choose);
int result(int inp, int outp, int n);
int input_from_console_str(char* str, int n);
int input_from_file_str(char* str, int n);
void punct_1_to_console (char* str);
void punct_1_to_file (char* str);
void punct_2_to_console (char* str, int n, int index_1);
void punct_2_to_file (char* str, int n, int index_1);
void punct_3_to_console (char* str, int index_1, int index_2, int n);
void punct_3_to_file (char* str, int index_1, int index_2, int n);
int output_str(char* str, int n, void (*punct1)(char*), void (*punct2)(char*, int, int), void (*punct3)(char*, int, int, int));

#endif