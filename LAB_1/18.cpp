#include <iostream>
#include <cmath>


int main()
{
    using namespace std;
    float a, b, c, R;
    cout << "Enter the angles of the triangle:\n";
    cin >> a >> b >> c;
    cout << "Enter the radius of the circumscribed circle\n";
    cin >> R;
    float A = 2 * R * sin(a/57.0);
    float B = 2 * R * sin(b/57.0);
    float C = 2 * R * sin(c/57.0);

    cout << "Sides of the triangle: " << A << " " << B << " " << C;
    return 0;
}