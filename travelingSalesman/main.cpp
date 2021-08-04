#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

bool check_path_unique(int* path, int pathL) {
    for (int i = 0; i < pathL; i++) {
        for (int j = 0; j < pathL; j++) {
            if (j == i) continue;
            if (path[i] == path[j]) return false;
        }
    }
    return true;
}

int factorial(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    int minDistance = numeric_limits<int>::max();

    int distances[n][n];
    int path[n];
    int variants[n];

    for (int i = 0; i < n; i++) {
        variants[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distances[i][j];
        }
    }

    int totalDistance, to, from;
    int variantsChecked = 0, vNum = 0;
    while (variantsChecked < factorial(n)) {
        while (true) {
            bool found = true;
            for (int i = 0; i < n; i++) {
                int currentVariant = (int) (vNum / pow(n, i)) % n;
                if (currentVariant == i) {
                    found = false;
                    break;
                }
                variants[i] = currentVariant;
            }
            vNum += 1;
            if (found) break;
        }
        if (!check_path_unique(variants, n)) continue;
        variantsChecked++;

        totalDistance = 0;
        for (int variant = 0; variant < n - 1; variant++) {
            from = variants[variant];
            to = variants[variant + 1];
            totalDistance += distances[from][to];
        }
        totalDistance += distances[to][variants[0]];

        // Write path
        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            for (int i = 0; i < n; i++) {
                path[i] = variants[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << minDistance;

    return 0;
}

