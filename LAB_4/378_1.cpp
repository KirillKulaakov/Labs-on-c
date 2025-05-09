#include "378.h"
#include "378_def.h"

namespace CONST {
    const char* FILE_INPUT = "../File_input.txt";
    const char* FILE_OUTPUT = "../File_output.txt";
}


int continue_programm(int* exit) {
    using namespace CONST;
    std::cout << std::endl << "You want to continue?";
    std::cout << std::endl << "Enter  y - to continue  or  any character - to exit: ";
    char ch;
    std::cin.get(ch);
    if (check_invalide() == ERROR) return ERROR;
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
    if (!(cin >> choose)) return ERROR;
    if (check_invalide() == ERROR) return ERROR;
    return choose;
}

int choose_user(int choose) {
    using namespace CONST;
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
    } else if (choose == 3) {
        inp = 2, outp = 1;
    } else if (choose == 4) {
        inp = 2, outp = 2;
    } else return ERROR;
    if (result(inp, outp, n) == ERROR) return ERROR;
    return SUCCESS;
}

int result(int inp, int outp, int n) {
    using namespace CONST;
    float *numbers = new(std::nothrow) float[n];
    float **matrix = new(std::nothrow) float*[n];
    if (numbers == nullptr || matrix == nullptr) return ERROR;
    if (matrix_initialization(matrix, numbers, n) == ERROR) return ERROR;
    if (inp == 1) { 
        if (enter_numbers_from_console(numbers, matrix, n) == ERROR) {
            clear_all(matrix, numbers, n);
            return ERROR; }
    } else if (inp == 2) { 
        if (enter_numbers_from_file(numbers, matrix, n) == ERROR) {
            clear_all(matrix, numbers, n);
            return ERROR; }
    }
    input_matrix(matrix, numbers, n);
    if (outp == 1) { 
        output_matrix_to_console(matrix, n);
    } else if (outp == 2) { 
        if (output_matrix_to_file(matrix, n) == ERROR) {
            clear_all(matrix, numbers, n);
            return ERROR; }
    }
    clear_all(matrix, numbers, n);
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

void clear_all(float** matrix, float* numbers, int n) {
    clear_memory(matrix, n);
    matrix = nullptr;
    delete[] numbers;
    numbers = nullptr;
}

void clear_memory(float** ptr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

int matrix_initialization(float** matrix, float* numbers, int n) {
    using namespace CONST;
    for (int i = 0; i < n; i++) {
        matrix[i] = new(std::nothrow) float[n];
        if (matrix[i] == nullptr) {
            clear_all(matrix, numbers, i);
            return ERROR;
        }
    }
    return SUCCESS;
}

int enter_numbers_from_console(float* numbers, float** matrix, int n) {
    using namespace CONST;
    using namespace std;
    cout << "Enter a " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> numbers[i])) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear();
            return ERROR;
        }
    }
    return check_invalide();
}

int enter_numbers_from_file(float* numbers, float** matrix, int n) {
    using namespace CONST;
    using namespace std;
    std::ifstream file(FILE_INPUT);
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            if (file.eof()) return ERROR;
            if (!(file >> numbers[i])) {
                cout << "incorrect number" << endl;
                return ERROR;
            }
        }
        char ch;
        while(file.get(ch)) {
            if (ch != '\n' && ch != ' ') {
                std::cout << "ERROR with values in file" << std::endl;
                file.close();
                return ERROR;
            }
        }
    } else return ERROR;
    file.close();
    return SUCCESS;
}

void input_matrix(float** matrix, float* numbers, int n) {
    double pow_number = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = pow(numbers[j], pow_number);
        }
        pow_number++;
    }
}

void output_matrix_to_console(float** matrix, int n) {
    using namespace std;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(12);
            cout.precision(5);
            cout << std::left << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int output_matrix_to_file(float** matrix, int n) {
    using namespace CONST;
    using namespace std;
    FILE* file = fopen(FILE_OUTPUT, "w");
    if (file != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(file, "%-12.5g ", matrix[i][j]);
            }
            fprintf(file, "\n");
        }
    } else return ERROR;
    fclose(file);
    return SUCCESS;
}