#include <iostream>
using namespace std;
void printParenthesis(int i, int j, int split[20][20])
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printParenthesis(i, split[i][j], split);
    printParenthesis(split[i][j] + 1, j, split);
    cout << ")";
}
int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    int p[20];
    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    int dp[20][20];
    int split[20][20];
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = 999999;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }
    cout << "\nMinimum number of multiplications = "
         << dp[1][n] << endl;
    cout << "Optimal Parenthesization = ";
    printParenthesis(1, n, split);
    cout << endl;
    return 0;
}