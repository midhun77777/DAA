#include <iostream>
#include <vector>
#include <limits>
using namespace std;

/*
    Matrix Chain Multiplication using Dynamic Programming

    Given matrices:
        A1 = p[0] x p[1]
        A2 = p[1] x p[2]
        ...
        An = p[n-1] x p[n]

    The program finds:
    1. Minimum number of scalar multiplications.
    2. Optimal order of multiplying the matrices.

    Time Complexity:  O(n^3)
    Space Complexity: O(n^2)
*/

// Prints the optimal parenthesization
void printOptimalOrder(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";

    printOptimalOrder(split, i, split[i][j]);
    cout << " x ";
    printOptimalOrder(split, split[i][j] + 1, j);

    cout << ")";
}

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of matrices must be greater than 0.\n";
        return 0;
    }

    // n matrices require n + 1 dimensions
    vector<int> dimensions(n + 1);

    cout << "Enter " << n + 1 << " dimensions:\n";
    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];

        if (dimensions[i] <= 0) {
            cout << "Dimensions must be positive.\n";
            return 0;
        }
    }

    // dp[i][j] stores the minimum multiplication cost
    // for matrices Ai through Aj.
    vector<vector<long long>> dp(
        n + 1,
        vector<long long>(n + 1, 0)
    );

    // split[i][j] stores the position where the optimal
    // multiplication chain is split.
    vector<vector<int>> split(
        n + 1,
        vector<int>(n + 1, 0)
    );

    // length = number of matrices in the current chain
    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;

            dp[i][j] = numeric_limits<long long>::max();

            // Try every possible split point
            for (int k = i; k < j; k++) {

                long long cost =
                    dp[i][k]
                    + dp[k + 1][j]
                    + 1LL * dimensions[i - 1]
                    * dimensions[k]
                    * dimensions[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications: "
         << dp[1][n] << endl;

    cout << "Optimal parenthesization: ";
    printOptimalOrder(split, 1, n);
    cout << endl;

    return 0;
}
```
