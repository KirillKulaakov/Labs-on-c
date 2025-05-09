#include "299.h"
#include "299_def.h"

float min(float* arr) {
    float min = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


float max(float* arr) {
    float max = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int check_invalide() {
    char ch;
    std::cin.get(ch);
    while (ch != '\n') {
        if (ch != ' ') return -1;
        std::cin.get(ch);
    }
    return 0;
}