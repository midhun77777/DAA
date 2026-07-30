#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

unsigned long long factIter(int n) {
    unsigned long long r = 1;
    while (n > 1) r *= n--;
    return r;
}

unsigned long long factRec(int n) {
    return (n <= 1) ? 1 : n * factRec(n - 1);
}

template <typename F>
double timeIt(F func, int n, unsigned long long &out) {
    auto t1 = high_resolution_clock::now();
    out = func(n);
    auto t2 = high_resolution_clock::now();
    return duration<double, nano>(t2 - t1).count();
}

int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid input!\n";
        return 1;
    }

    unsigned long long r1, r2;
    double t1 = timeIt(factIter, n, r1);
    double t2 = timeIt(factRec, n, r2);

    cout << "\n" << n << "! Results\n";
    cout << "Iterative: " << r1 << "  (" << t1 << " ns)\n";
    cout << "Recursive: " << r2 << "  (" << t2 << " ns)\n";

    return 0;
}
