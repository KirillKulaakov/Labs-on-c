#include "186.h"

int main() {
    using namespace std;

    int n;
    char ch;
    cout << "Enter a 'n': ";
    if (!(cin >> n)) return -1;
    cin.get(ch);
    while (ch != '\n') {
        if (ch != ' ') {
            return -1;
        }
        cin.get(ch);
    }
    cout << "Enter a elements: ";
    if (result(n) == -1) {
        return -1;
    }
    return 0;
}
