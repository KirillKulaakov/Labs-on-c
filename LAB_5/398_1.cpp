#include "398.h"
#include "398_const.h"



int continue_programm(int* exit) {
    using namespace CONST;
    std::cout << std::endl << "You want to continue?";
    std::cout << std::endl << "Enter  y - to continue  or  any character - to exit: ";
    char ch;
    std::cin.get(ch);
    if (check_invalide() == ERROR) {
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
    } else if (check_invalide() == ERROR) {return ERROR;}
    return choose;
}

int choose_user(const int& choose) {
    using namespace CONST;
    int n, inp = 1, outp = 1;
    std::string name_file_output = FILE_OUTPUT, name_file_input = FILE_INPUT;
    if (choose >= 1 && choose <= 4) {
        std::cout << "PLZ ENTER a n: ";
        if (!(std::cin >> n) || n <= 0) {
            invalide_value();
            return ERROR; }
    } else {
        invalide_value();
        return ERROR;
    } if (check_invalide() == ERROR) {
        invalide_value();
        return ERROR;
    } if (choose == 2){
        inp = 1, outp = 2;
        name_file_output = input_name_of_file_to_output();
    } else if (choose == 3) {
        inp = 2, outp = 1;
        name_file_input = input_name_of_file_to_input();
    } else if (choose == 4) {
        inp = 2, outp = 2;
        name_file_input = input_name_of_file_to_input(), name_file_output = input_name_of_file_to_output();
    }
    if (result(inp, outp, n, name_file_input, name_file_output) == ERROR) return ERROR;
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


int result(int& inp, int& outp,const int& n, std::string& name_file_input, std::string& name_file_output) {
    using namespace CONST;
    std::vector<std::vector<double>> matrix;
    if (inp == 1) { 
        if (enter_matrix_from_console(matrix, n) == ERROR) {
            invalide_value();
            return ERROR; 
        }
    } else if (inp == 2) { 
        if (enter_matrix_from_file(matrix, n, name_file_input) == ERROR) {
            return ERROR; 
        }
    }
    double sum1{}, sum2{}, sum3{};
    sum_the_element(matrix, n, sum1, sum2, sum3);
    if (outp == 1) { 
        output_sum_to_console(sum1, sum2, sum3);
    } else if (outp == 2) { 
        if (output_sum_to_file(sum1, sum2, sum3, name_file_output) == ERROR) {return ERROR;}
    }
    return SUCCESS;
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

int enter_matrix_from_console(std::vector<std::vector<double>>& matrix, const int& n) {
    using namespace CONST;
    double number;
    std::cout << "Enter a matrix[" << n << "][" << n << "]: ";
    for (int i{}; i < n; i++) {
        std::vector<double> numbers;
        for (int j{}; j < n; j++) {
            if (!(std::cin >> number)) {
                std::cout << "ERROR with enter a number" << std::endl;
                return ERROR;
            }
            numbers.push_back(number);
        }
        matrix.push_back(numbers);
    }
    if (check_invalide() == ERROR) {
        invalide_value();
        return ERROR;
    }
    return SUCCESS;
}

int enter_matrix_from_file(std::vector<std::vector<double>>& matrix, const int& n, const std::string& name_file_input) {
    using namespace CONST;
    double number;
    std::ifstream file(name_file_input);
    if (file.is_open()) {
        for (int i{}; i < n; i++) {
            std::vector<double> numbers;
            for (int j{}; j < n; j++) {
                if (!(file >> number)) {
                    std::cout << "ERROR with enter a number" << std::endl;
                    return ERROR;
                }
                numbers.push_back(number);
            }
            matrix.push_back(numbers);
        }
    } else {
        std::cout << "ERROR with open the file" << std::endl;
        return ERROR;
    }
    char ch;
    while(file.get(ch)) {
        if (ch != '\n' && ch != ' ') {
            std::cout << "ERROR with values in file" << std::endl;
            file.close();
            return ERROR;
        }
    }
    file.close();
    return SUCCESS;
}


void sum_the_element(const std::vector<std::vector<double>>& matrix, const int& n, double& sum1, double& sum2, double& sum3) {
    using namespace CONST;
    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            if (matrix[i][0] < 0) {
                if (j > i) sum1 += matrix[i][j];
                else if (j == i) sum2 += matrix[i][j];
                else sum3 += matrix[i][j];
            }
        }
    }
}

void output_sum_to_console(const double& sum1, const double& sum2, const double& sum3) {
    std::cout << "The sum of the elements above the main diagonal: " << sum1 << std::endl;
    std::cout << "The sum of the elements on the main diagonal: " << sum2 << std::endl;
    std::cout << "The sum of the elements under the main diagonal: " << sum3 << std::endl;
}

int output_sum_to_file(const double& sum1, const double& sum2, const double& sum3, const std::string name_file_output) {
    using namespace CONST;
    std::ifstream f(name_file_output);
    if (f.is_open()) {
        std::ofstream file(name_file_output);
        if (file.is_open()) {
            std::cout << "Write to file" << std::endl;
            file << "The sum of the elements above the main diagonal: " << sum1 << "\n";
            file << "The sum of the elements on the main diagonal: " << sum2 << "\n";
            file << "The sum of the elements under the main diagonal: " << sum3 << "\n";
        } else {
            std::cout << "ERROR with open the file" << std::endl;
            return ERROR;
        }
        file.close();
    } else std::cout << "ERROR with output file" << std::endl;
    return SUCCESS;
}

void invalide_value() {
    std::cout << "Invalide value" << std::endl;
}