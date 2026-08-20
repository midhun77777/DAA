#include <iostream>
#include <vector>
using namespace std;

int main() {
    int coins[] = {1, 3, 4};
    int n = 3;
    int amount = 6;

    vector<int> dp(amount + 1, amount + 1);

    // dp[0] = 0 because no coin is needed for amount 0
    dp[0] = 0;

    // Find minimum coins for each amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {

            if (coins[j] <= i) {
                dp[i] = min(dp[i],
                            dp[i - coins[j]] + 1);
            }
        }
    }

    cout << "Minimum number of coins = "
         << dp[amount] << endl;

    cout << "Minimum coins required: ";

    int current = amount;

    while (current > 0) {

        for (int j = n - 1; j >= 0; j--) {

            if (coins[j] <= current &&
                dp[current] == dp[current - coins[j]] + 1) {

                cout << coins[j] << " ";
                current = current - coins[j];
                break;
            }
        }
    }

    cout << endl;

    return 0;
}
