#include "268.h"
#include "268_def.h"

namespace pack {
    const char* FILE_INPUT = "../File_input.txt"; 
    const char* FILE_OUTPUT = "../File_output.txt"; 
}

bool is_cin(const std::istream& stream) {
    return &stream == &std::cin;
}

int choose_user(int choose) {
    using namespace pack;
    int inp = 1, outp = 1;
    if (choose == 2){
        inp = 1, outp = 2;
    } else if (choose == 3) {
        inp = 2, outp = 1;
    } else if (choose == 4) {
        inp = 2, outp = 2;
    } else if (choose != 1) return ERROR;
    if (result(inp, outp) == ERROR) return ERROR;

    return SUCCESS;
}

int result(int inp, int outp) {
    using namespace pack;
    char *str = nullptr, *str_res = nullptr;
    int n;
    if (inp == 1) { 
        if (input_arr(std::cin, &str, n) == ERROR) {
            delete[] str;
            return ERROR; }
    } else if (inp == 2) {
        std::ifstream file(FILE_INPUT);
        if (!file.is_open()) return ERROR; 
        if (input_arr(file, &str, n) == ERROR) {
            delete[] str;
            return ERROR; }
    }
    str_res = new(std::nothrow) char[n+1];
    if (str_res == nullptr) {
        delete[] str;
        return ERROR;
    }
    result_arr(str, str_res, n); 
    if (outp == 1) { 
        output_arr(std::cout, str_res);
    } else if (outp == 2) { 
        std::ofstream file(FILE_OUTPUT);
        if (!file.is_open()) {
            delete_memory(str, str_res);
            return ERROR;} 
        output_arr(file, str_res);
    }
    delete_memory(str, str_res);
    return SUCCESS;
}


void result_arr(char* str, char* str_res, int n) {
    int count_not_space = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') str_res[count_not_space++] = str[i];
        else if (count_not_space != 0 && str[i] == ' ' && (i + 1) < n && str[i+1] != ' ') str_res[count_not_space++] = str[i];
    }
    str_res[count_not_space] = '\0';
}


void delete_memory(char* str_1, char* str_2) {
    delete[] str_1;
    delete[] str_2;
}


int continue_programm(int* exit) {
    using namespace pack;
    std::cout << std::endl << "You want to continue?";
    std::cout << std::endl << "Enter  y - to continue  or  any character - to exit: ";
    char ch;
    std::cin.get(ch);
    if (check_invalide(std::cin) == ERROR) return ERROR;
    if (ch != 'y') *exit = 1;
    return SUCCESS;
}
int choose_form_input_output() {
    using namespace std;
    using namespace pack;
    cout << endl <<"ENTER 1 number: " << endl; 
    cout << "1) input values - console   /   output values - console" << endl;
    cout << "2) input values - console   /   output values - file" << endl;
    cout << "3) input values - file      /   output values - console" << endl;
    cout << "4) input values - file      /   output values - file" << endl;
    int choose;
    if (!(cin >> choose)) return ERROR;
    if (check_invalide(std::cin) == ERROR) return ERROR;
    return choose;
}