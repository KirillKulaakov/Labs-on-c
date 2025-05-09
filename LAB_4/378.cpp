#include "378.h"
#include "378_def.h"

int main() {
    using namespace std;
    using namespace CONST;
    int exit = SUCCESS;
    while (!exit) {
        int choose = choose_form_input_output();
        if (choose_user(choose) == ERROR) {
            cout << "ERROR";
            return ERROR;
        }
        if (choose == 3 || choose == 4) {
            exit = 1;
        } else if (choose == 1 || choose == 2) {
            if (continue_programm(&exit) == ERROR) {
                cout << "ERROR";
                return ERROR;
            }
        }
    }

    return 0;
}