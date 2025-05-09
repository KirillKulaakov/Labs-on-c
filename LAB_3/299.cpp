#include "299.h"
#include "299_def.h"

int main() {
    using namespace std;

    float arr[N], value = 0;
    cout << "Enter a 26 numbers: ";
    for (int i = 0; i < N; i++) {
        if (!(cin >> arr[i])) {
            cout << "ERROR";
            return -1;
        }
    }
    if (check_invalide() == -1) return -1;
    else if (arr[0] >= 0) {
        value = min(arr);
    } else {
        value = max(arr);
    }
    for (int i = 0; i < N; i++) {
        arr[i] = arr[i] * (value * value);
        cout << arr[i] << " ";
    }
    return 0;
}

//2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
//2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1 11.1 12.1 13.1 14.1 15.1 16.1 17.1 18.1 19.1 20.1 21.1 22.1 23.1 24.1 25.1 26.1 27.1