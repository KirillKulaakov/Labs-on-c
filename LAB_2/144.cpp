#include "144.h"

int main() {
    using namespace std;

    int n;
    char ch;
    cout << "Enter a 'n': ";
    cin >> n;
    if (n <= 1) return 0;
    cin.get(ch);
    while (ch != '\n') {
        if (ch != ' ') {
            cout << "ERROR";
            return -1;
        }
        cin.get(ch);
    }
    cout << "a) ";
    for (int i = 0; i < n; i++) {
        cout << fibonachi_a(i) << " ";
    }
    cout << endl << "b) ";
    for (int i{}; i < n; i++) {
        cout << fibonachi_b(i) << " ";
    }
    return 0;
}
