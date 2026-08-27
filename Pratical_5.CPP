#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n + 1);
    vector<int> value(n + 1);

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Dynamic Programming
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (weight[i] <= w) {
                dp[i][w] = max(
                    value[i] + dp[i - 1][w - weight[i]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum value: " << dp[n][capacity] << endl;

    return 0;
}
