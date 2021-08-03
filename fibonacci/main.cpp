#include <iostream>
#include <chrono>
using namespace std;

unsigned int fibonacciIterative(unsigned int n) {
    unsigned int previous = 0;
    unsigned int current = 1;
    unsigned int tmp, result;

    for (int i = 0; i < n; i++) {
        result = current;
        tmp = previous;
        previous = current;
        current += tmp;
    }

    return result;
}

unsigned int fibonacciRecursive(unsigned int n) {
    if (n > 2) {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
    return 1;
}

int main() {
    unsigned int n, result;
    cout << "Write a number:\n";
    cin >> n;

    auto start = chrono::steady_clock::now();
    result = fibonacciIterative(n);
    auto end = chrono::steady_clock::now();
    cout << "Iterative:\n" << endl;
    cout << result << "\n";
    chrono::duration<double> time = end - start;
    double seconds = time.count();
    cout << fixed << "Tooks: " << seconds << " seconds" << "\n";

    start = chrono::steady_clock::now();
    result = fibonacciRecursive(n);
    end = chrono::steady_clock::now();
    cout << "Recursive:\n";
    cout << result << "\n";
    time = end - start;
    seconds = time.count();
    cout << fixed << "Tooks: " << seconds << " seconds" << "\n";

    return 0;
}
