#include <bits/stdc++.h>
using namespace std;
/*
Implementing the coin change problem using dynamic programming, where we need to find the number of ways to make a sum using a given set of coins.
*/
int main()
{
    int n, sum;
    cin >> n >> sum;
    int val;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - v[j] >= 0)
            {
                dp[i] = dp[i] + dp[i - v[j]];
            }
        }
        cout << endl;
    }
    cout << dp[sum] << endl;
    return 0;
}