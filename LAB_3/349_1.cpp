#include "349.h"

void unic_number(int* arr, int n, int *count, int* arr_unic) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < *count; j++) {
            if (arr_unic[j] == arr[i]) {
                flag = 1;
            }
        }
        if (!flag) {
            arr_unic[*count] = arr[i];
            (*count)++;
        }
    }
}

void output(int* arr, int* arr_unic_2, int count, int n) {
    for (int i = 0; i < count; i++) {
        int count_i = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr_unic_2[i]) count_i++;
        }
        std::cout << arr_unic_2[i] << " - " << count_i << std::endl;
    }
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