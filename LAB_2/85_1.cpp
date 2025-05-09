#include "85.h"

void output_sum(float a, float h, int n) {
    float sum = 0.0;
    for (int i = 0; i < n + 1; i++) {
        sum += (a * a + 1) * cos(a) * cos(a);
        if (i != 0 && i != n) {
            sum *= 2;
        }
        a += h;
    }
    std::cout << "Result: " << sum;
}