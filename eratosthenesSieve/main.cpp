#include <iostream>
using namespace std;

int main() {
    int numToCheck;
    cin >> numToCheck;

    if (numToCheck <= 1) {
        cout << "Invalid number!";
    }

    int n = numToCheck - 1;

    bool arePrimes[n];
    int numbers[n];

    for (int i = 0; i < n; i++) {
        arePrimes[i] = true;
    }
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 2;
    }

    int step;
    for (int i = 0; i < n; i++) {
        if (!arePrimes[i]) {
            continue;
        }

        step = numbers[i];

        for (int j = i + step; j < n; j += step) {
            arePrimes[j] = false;
        }
    }

    if (arePrimes[n-1]) {
        cout << "Prime";
    } else {
        cout << "Not Prime";
    }

    return 0;
}
