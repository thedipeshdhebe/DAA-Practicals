#include <iostream>
using namespace std;
int main()
{
    int n, amount;
    cout << "Enter number of coins: ";
    cin >> n;
    int coin[n];
    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    cout << "Enter amount: ";
    cin >> amount;
    int dp[amount + 1];
    int used[amount + 1]; 
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = 9999;
        used[i] = -1;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coin[j] <= i)
            {
                if (dp[i - coin[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin[j]] + 1;

                
                    used[i] = coin[j];
                }
            }
        }
    }
    if (dp[amount] == 9999)
    {
        cout << "Change cannot be made." << endl;
    }
    else
    {
        cout << "\nMinimum number of coins = " << dp[amount] << endl;
        cout << "Coins used: ";
        int x = amount;
        while (x > 0)
        {
            cout << used[x] << " ";
            x = x - used[x];
        }
        cout << endl;
    }
    return 0;
}