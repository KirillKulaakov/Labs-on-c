#include <string>
#include "258.h"
#include "258_const.h"

namespace CONST {
    const std::string FILE_INPUT = "../File_input.txt";
    const std::string FILE_OUTPUT = "../File_output.txt";
}


int continue_programm(int* exit) {
    using namespace CONST;
    std::cout << std::endl << "You want to continue?";
    std::cout << std::endl << "Enter  y - to continue  or  any character - to exit: ";
    char ch;
    std::cin.get(ch);
    if (check_invalide(std::cin) == ERROR) {
        invalide_value();
        return ERROR;
    }
    if (ch != 'y') *exit = 1;
    return SUCCESS;
}

int choose_form_input_output() {
    using namespace std;
    using namespace CONST;
    cout << endl <<"ENTER 1 number: " << endl; 
    cout << "1) input values - console   /   output values - console" << endl;
    cout << "2) input values - console   /   output values - file" << endl;
    cout << "3) input values - file      /   output values - console" << endl;
    cout << "4) input values - file      /   output values - file" << endl;
    int choose;
    if (!(cin >> choose)) {
        return ERROR;
    } else if (check_invalide(std::cin) == ERROR) {
        invalide_value();
        return ERROR;
    }
    return choose;
}

int choose_user(const int& choose) {
    using namespace CONST;
    int inp = 1, outp = 1;
    std::string name_file_output = FILE_OUTPUT, name_file_input = FILE_INPUT;

    if (choose == 1) {
        inp = 1, outp = 1; 
    } 
    else if (choose == 2){
        inp = 1, outp = 2;
        name_file_output = input_name_of_file_to_output();
    } 
    else if (choose == 3) {
        inp = 2, outp = 1;
        name_file_input = input_name_of_file_to_input();
    } 
    else if (choose == 4) {
        inp = 2, outp = 2;
        name_file_input = input_name_of_file_to_input(), name_file_output = input_name_of_file_to_output();
    } 
    else    
        return ERROR;

    if (result(inp, outp, name_file_input, name_file_output) == ERROR) return ERROR;
    return SUCCESS;
}


std::string input_name_of_file_to_output() {
    using namespace CONST;
    std::string name_of_file;
    std::cout << "Input a Name of file output: ";
    std::getline(std::cin, name_of_file);
    if (name_of_file.empty()) name_of_file = FILE_OUTPUT;
    return name_of_file;
}


std::string input_name_of_file_to_input() {
    using namespace CONST;
    std::string name_of_file;
    std::cout << "Input a Name of file input: ";
    std::getline(std::cin, name_of_file);
    if (name_of_file.empty()) name_of_file = FILE_INPUT;
    return name_of_file;
}

int result(int& inp, int& outp, std::string& name_file_input, std::string& name_file_output) {
    using namespace CONST;
    std::string str;
    int n;
    
    if (inp == 1) { 
        if (input_from_console_str(str, n) == ERROR) 
            return ERROR;
    } 
    else if (inp == 2) { 
        if (input_from_file_str(str, name_file_input, n) == ERROR) 
            return ERROR;
    }
    
    if (check_length_string(str, n) == ERROR) {return ERROR;}
    delete_the_sequence(str);
    if (outp == 1) { 
        output_str_to_console(str);
    }else if (outp == 2) { 
        if (output_str_to_file(str, name_file_output) == ERROR) {return ERROR;}
    }
    return SUCCESS;
}

int input_from_console_str(std::string& str, int& n) {
    std::cout << "PLZ Enter n: ";
    if (!(std::cin >> n) || n <= 0) return CONST::ERROR;
    if (check_invalide(std::cin) == CONST::ERROR) return CONST::ERROR;
    std::cout << "Enter a " << n << " simbols: ";
    std::getline(std::cin, str);
    return CONST::SUCCESS;
}

int input_from_file_str(std::string& str, std::string& name_file_input, int& n) {
    using namespace CONST;
    int flag = SUCCESS;
    std::ifstream file(name_file_input);
    if (file.is_open()) {
        std::cout << "Read the file" << std::endl;
        if (!(file >> n) || n <= 0) flag = ERROR; 
        if (check_invalide(file) == ERROR) flag = ERROR;
        else std::getline(file, str);
    } else {
        std::cout << "ERROR with open the input file" << std::endl;
        flag = ERROR;
    }
    file.close();
    return flag;
}

void output_str_to_console(const std::string& str) {
    std::cout << str << std::endl;
}


int output_str_to_file(const std::string& str, const std::string& name_file_output) {
    using namespace CONST;
    std::ifstream f(name_file_output);
    if (f.is_open()) {
        f.close();
        std::fstream file(name_file_output, std::ios::out);
        if (file.is_open()) {
            std::cout << "Write in file" << std::endl;
            file << str;
        } else {
            std::cout << "ERROR with open the file" << std::endl;
            return ERROR;
        }
        file.close();
    } else std::cout << "ERROR with open the output file" << std::endl;
    return SUCCESS;
}

int check_length_string(const std::string& str, const int& n) {
    using namespace CONST;
    if (str.size() != static_cast<size_t>(n)) {
        std::cout << "ERROR with length string" << std::endl;
        return ERROR;
    }
    return SUCCESS;
}


void delete_the_sequence(std::string& str) {
    unsigned i{3};
    while (i < str.size()) {
        if (i >= 3 && static_cast<int>(str[i]) - static_cast<int>(str[i-1]) == 1 &&
        static_cast<int>(str[i-1]) - static_cast<int>(str[i-2]) == 1 &&
        static_cast<int>(str[i-2]) - static_cast<int>(str[i-3]) == 1) {
            str.erase(i-3, 4);
            i -= 3;
        }
        i++;
    }
}

int check_invalide() {
    using namespace CONST;
    char ch;
    std::cin.get(ch);
    while (ch != '\n') {
        if (ch != ' ') return ERROR;
        std::cin.get(ch);
    }
    return SUCCESS;
}

void invalide_value() {
    std::cout << "Invalide value" << std::endl;
}