#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;
    cout << "enter a, b, c\n";
    cin >> a >> b >> c;
    if (a == 0) return -1;
    float D = b * b - 4 * a * c;
    if (D > 0) {
        float x1 = (-b +  sqrt(D)) / (2 * a);
        float x2 = (-b - sqrt(D)) / (2 * a);
        cout << "x1, x2: " << x1 << "  " <<x2;
    } else if (D == 0) {
        float x = (-b) / (2 * a);
        cout << "x = " << x;
    } else {
        cout << "no koren";
    }
    return 0;
}