#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, c;
    cout << "Enter number of items: ";
    cin >> n;
    int weight[n], profit[n];
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter profits of items: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    cout << "Enter capacity of knapsack: ";
    cin >> c;
    int dp[n + 1][c + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= c; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    cout << "\nMaximum profit = " << dp[n][c] << endl;
    int w = c;
    int totalWeight = 0;
    cout << "\nSelected items:\n";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i
                 << " -> Weight = " << weight[i - 1]
                 << ", Profit = " << profit[i - 1] << endl;
            totalWeight += weight[i - 1];
            w = w - weight[i - 1];
        }
    }
    cout << "\nTotal weight used = " << totalWeight << endl;
    cout << "Remaining capacity = " << c - totalWeight << endl;
    return 0;
}