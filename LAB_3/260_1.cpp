#include "260_1.h"
#include "260_2.h"
#include "260_def.h"

namespace pack {
    const char* FILE_INPUT = "File_input.txt"; 
    const char* FILE_OUTPUT = "File_output.txt"; 
}


int choose_user(int choose) {
    using namespace pack;
    int n;
    int inp = 1, outp = 1;
    if (choose >= 1 && choose <= 4) {
        std::cout << "PLZ ENTER a n: ";
        if (!(std::cin >> n) || n <= 0) return ERROR;
    } else return ERROR;
    if (check_invalide() == ERROR) return ERROR;
    if (choose == 1) {
        inp = 1, outp = 1; 
    } else if (choose == 2){
        inp = 1, outp = 2;
    } else if (choose ==3) {
        inp = 2, outp = 1;
    } else if (choose == 4) {
        inp = 2, outp = 2;
    } else return ERROR;
    if (result(inp, outp, n) == ERROR) return ERROR;
    return SUCCESS;
}

int result(int inp, int outp, int n) {
    using namespace pack;
    char* str = new(std::nothrow) char[n+1];
    if (str == nullptr) return ERROR;
    if (inp == 1) { 
        if (input_from_console_str(str, n) == ERROR) {
            delete[] str;
            return ERROR; }
    } else if (inp == 2) { 
        if (input_from_file_str(str, n) == ERROR) {
            delete[] str;
            return ERROR; } 
    } if (outp == 1) { 
        if (output_str(str, n, punct_1_to_console, punct_2_to_console, punct_3_to_console) == ERROR) {
            delete[] str;
            return ERROR; } 
    }else if (outp == 2) { 
        if (output_str(str, n, punct_1_to_file, punct_2_to_file, punct_3_to_file) == ERROR) {
            delete[] str;
            return ERROR; }
    }
    delete[] (str);
    str = nullptr;
    return SUCCESS;
}

int output_str(char* str, int n, void (*punct1)(char*), void (*punct2)(char*, int, int), void (*punct3)(char*, int, int, int)) {
    using namespace pack;
    int index_1 = find_index(str, ':', 0);
    if (index_1 != ERROR) {
        int index_2 = find_index(str, ':', index_1 + 1);
        punct1(str);
        if (index_1 != n - 1) punct2(str, n, index_1);
        if (index_2 != ERROR) punct3(str, index_1, index_2, n);
    } else return ERROR;
    return SUCCESS;
}


int input_from_console_str(char* str, int n) {
    using namespace pack;
    std::cout << "PLZ ENTER A SIMBOLS: ";
    for (int i = 0 ; i < n; i++) {
        std::cin.get(str[i]);
    }
    str[n] = '\0';
    if (check_invalide() == ERROR) return ERROR;
    return SUCCESS;
}

int input_from_file_str(char* str, int n) {
    using namespace pack;
    std::ifstream file(FILE_INPUT);
    int count = 0;
    if (file.is_open()) {
        file.read(str, n);
        std::streamsize bytesRead = file.gcount();
        if (bytesRead != n) {
            file.close();
            return ERROR;
        }
    } else return ERROR;
    file.close();
    return SUCCESS;
}


void punct_1_to_console (char* str) {
    std::cout << "a)";
    const char* ptr = str;
    while (*ptr) {
        if (*ptr == ':') {
            std::cout << *ptr;
            break;
        }
        std::cout << *(ptr++);
    }
}

void punct_1_to_file (char* str) {
    using namespace pack;
    std::ofstream file(FILE_OUTPUT);
    file << "a)";
    char* ptr = str;
    while (*ptr) {
        if (*ptr == ':') {
            file << *ptr;
            break;
        }
        file << *(ptr++);
    }
    file.close();
}

void punct_2_to_console (char* str,int n, int index_1) {
    std::cout << std::endl << "b)";
    for (int i = index_1 + 1; i < n; i++) {
        std::cout << str[i];
    }
}

void punct_2_to_file (char* str, int n, int index_1) {
    using namespace pack;
    std::ofstream file(FILE_OUTPUT, std::ios::app);
    file << std::endl << "b)";
    for (int i = index_1 + 1; i < n; i++) {
        file << str[i];
    }
    file.close();
}

void punct_3_to_console (char* str, int index_1, int index_2, int n) {
    std::cout << std::endl << "c)";
    for (int i = 0; i < n; i++) {
        if (i > index_1 && i < index_2) {
            std::cout << str[i];
        }
    }
}

void punct_3_to_file (char* str, int index_1, int index_2, int n) {
    using namespace pack;
    std::ofstream file(FILE_OUTPUT, std::ios::app);
    file << std::endl << "c)";
    for (int i = 0; i < n; i++) {
        if (i > index_1 && i < index_2) {
            file << str[i];
        }
    }
    file.close();
}
