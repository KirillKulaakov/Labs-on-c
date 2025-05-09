#include "186.h"

int factorial(int n) {
    int mul = 1;
    for (int i = 1; i < n + 1; i++) {
        mul *= i;
    }
    return mul;
}

int result(int n) {
    using namespace std;
    
    float number;
    int count = 0;
    char ch;
    long double mul_reverse = 1.0;
    for (int i = 0; i < n; i++) {
        if (!(cin >> number)) return -1;
        cin.get(ch);
        if (ch != ' ' && ch != '\n') return -1;
        else if ((i + 1) < number && number < factorial(i)){
            mul_reverse *= number;
        } 
        count++;
        if (count == n && ch != '\n') {
            cin.get(ch);
            while (ch != '\n') {
                if (ch != ' ') return -1;
                cin.get(ch);
            }
        }
    }
    cout << "Reverse mul: " << 1.0 / mul_reverse;
    return 0;
}