#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float f;
    cout << "Enter a angle\n";
    cin >> f;
    if (f <= 0 && 360 <= f) {
        return -1;
    }
    int hours  = f / 30;
    while (f > 30.0) {
        f -= 30.0;
    }
    float angle = f * 12.0;
    cout << "angle of minute " << angle << endl;
    int minutes = angle / 6.0;
    cout << hours<< " hours\t"<< minutes << " minutes";
    return 0;
}

