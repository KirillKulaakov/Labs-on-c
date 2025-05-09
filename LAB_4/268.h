#ifndef HEADER

#include <iostream>
#include <new>
#include <fstream>
#include "268_def.h"

#define HEADER


void result_arr(char* str, char* str_res, int n);
void delete_memory(char*, char*);
void delete_memory(char* str1, char* str2);

int choose_user(int choose);
int result(int inp, int outp, int n);
int choose_form_input_output();
int continue_programm(int* exit);


template <typename Type>
int check_invalide(Type& stream) {
    using namespace pack;
    char ch;
    if constexpr (std::is_same<Type, std::ifstream>::value || std::is_same<Type, std::fstream>::value) {
        if (!(stream.get(ch))) return SUCCESS;
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
int input_arr(Type& stream, char* str, int n) {
    using namespace pack;
    char ch;
    int count = 0;
    while (count != n) {
        if (!stream.get(ch)) return ERROR;
        str[count] = ch;      
        count++;
    }
    if (check_invalide(stream) == ERROR) return ERROR;
    if constexpr (std::is_same<Type, std::ifstream>::value || std::is_same<Type, std::fstream>::value) stream.close();
    return SUCCESS;
}


template <typename Type>
void output_arr(Type& stream, char* str_res) {
    char* ptr = str_res;
    while (*ptr) {
        stream << *ptr;
        ptr++;
    } 
    if constexpr (std::is_same<Type, std::ifstream>::value || std::is_same<Type, std::fstream>::value) stream.close();
}


#endif