#include "144.h"

int fibonachi_a(int n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;
    return fibonachi_a(n - 1) + fibonachi_a(n - 2);
}

int fibonachi_b(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fibonachi_b(n - 1) + fibonachi_b(n - 2) + fibonachi_a(n - 2);
}