#include "260_2.h"
#include "260_def.h"

int continue_programm(int* exit) {
    using namespace pack;
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
    using namespace pack;
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


int check_invalide() {
    using namespace pack;
    char ch;
    std::cin.get(ch);
    while (ch != '\n') {
        if (ch != ' ') return ERROR;
        std::cin.get(ch);
    }
    return SUCCESS;
}

int find_index(char* str, char ch, int parametr) {
    using namespace pack;
    char* ptr = str + parametr;
    int index = parametr;
    while (*ptr) {
        if (*ptr == ch) {
            return index;
        }
        ptr++;
        index++;
    }
    return ERROR;
}