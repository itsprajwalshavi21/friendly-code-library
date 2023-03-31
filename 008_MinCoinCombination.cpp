#include <bits/stdc++.h>
using namespace std;

/*
Find the minimum number of coins required to make the target sum using dynamic programming
*/

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> c;
    int val;
    int min;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        c.push_back(val);
    }
    vector<int> dp(sum + 1);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
            {
                val = dp[i - c[j]] + 1;
                if (val < min)
                {
                    min = val;
                }
            }
        }
        dp[i] = min;
    }
    cout << dp[sum] << endl;
    return 0;
}