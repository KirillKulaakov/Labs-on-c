#include "349.h"

int main() {
    using namespace std;

    int n, count = 0;
    cout << "Enter a n: ";
    if (!(cin >> n)) return -1;
    if(check_invalide() == -1) return -1;
    int arr[n], arr_unic[n];
    cout << "Enter a massive: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) return -1;
    }
    if(check_invalide() == -1) return -1;
    unic_number(arr, n, &count, arr_unic);
    int arr_unic_2[count];
    for (int i = 0; i < count; i++) {
        arr_unic_2[i] = arr_unic[i];
    }
    output(arr, arr_unic_2, count, n);
    return 0;
}