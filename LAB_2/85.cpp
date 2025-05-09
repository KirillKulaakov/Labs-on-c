#include "85.h"

int main() {
    using namespace std;

    float a, h, sum = 0.0;
    int n;
    cout << "Enter a, h:" << endl;
    cin >> a >> h;
    cout << "Enter a 'n':" << endl;
    cin >> n;
    output_sum(a, h, n);
    return 0;
}