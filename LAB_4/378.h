

#ifndef HEADER

#define HEADER

#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include "378_def.h"


int continue_programm(int* exit);
int choose_form_input_output();
int choose_user(int choose);
int result(int inp, int outp);
void clear_memory(float** ptr, int n);
int enter_numbers_from_console(float* numbers, int n);
void input_matrix(float** matrix, float* numbers, int n);
void output_matrix_to_console(float** matrix, int n);
int output_matrix_to_file(float** matrix, int n);
void clear_all(float** matrix, float* numbers, int n);
bool is_cin(const std::istream& stream);


template <typename Type>
int enter_numbers_from_file(Type& stream, float* numbers, int n) {
    using namespace CONST;
    using namespace std;
    std::cout << "START FILE READ\n";
    for (int i = 0; i < n; i++) {
        if (stream.eof()) {
            std::cout << "END of file\n";
            return ERROR;
        }
        
        if (!(stream >> numbers[i])) {
            cout << "incorrect number" << endl;
            return ERROR;
        }
    }
    char ch;
    while(stream.get(ch)) {
        if (ch != '\n' && ch != ' ') {
            std::cout << "ERROR with values in file" << std::endl;
            return ERROR;
        }
    }
    return SUCCESS;
}

template <typename Type>
int check_invalide(Type& stream) {
    using namespace CONST;
    char ch;
    if constexpr (std::is_same<Type, std::ifstream>::value || std::is_same<Type, std::fstream>::value) {
        if (!(stream.get(ch)) || ch == '\n') return SUCCESS;
        return ERROR;
    } else {
        if (!(stream.get(ch))) return SUCCESS;
        while(ch != '\n') {
            if (ch != ' ') return ERROR;
            stream.get(ch);
        }
    }
    return SUCCESS;
}

template <typename Type>
int matrix_initialization(Type& stream, int inp, float*** matrix, float** numbers, int& n) {
    using namespace CONST;
    char ch = ' ';
    if (is_cin(stream)) {
        std::cout << "PLZ enter n: ";
    }
    if (!(stream >> n) || n <= 0) return ERROR;
    stream.get(ch);
    if (ch != '\n') {
        return ERROR;
    }
    else {
        *numbers = new(std::nothrow) float[n];
        *matrix = new(std::nothrow) float*[n];
        if (*numbers == nullptr || *matrix == nullptr) {
            clear_all(*matrix, *numbers, 0);
            return ERROR;
        }
    }
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = new(std::nothrow) float[n];
        if ((*matrix)[i] == nullptr) {
            clear_all(*matrix, *numbers, i);
            return ERROR;
        }
    }
    if (inp == 1) { 
        if (enter_numbers_from_console(*numbers, n) == ERROR) {
            clear_all(*matrix, *numbers, n);
            return ERROR; }
    } else if (inp == 2) { 
        if (enter_numbers_from_file(stream, *numbers, n) == ERROR) {
            clear_all(*matrix, *numbers, n);
            return ERROR; }
    }
    return SUCCESS;
}




#endif


