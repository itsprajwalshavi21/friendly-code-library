#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount)
{
    // Write your code here
    vector<int> nums = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = nums.size();

    int minCoins = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (amount / nums[i] >= 1)
        {
            minCoins += amount / nums[i];
            amount %= nums[i];
        }

        if (amount == 0)
            break;
    }

    return minCoins;

    //     Method-2
    vector<vector<int>> memo(n + 1, vector<int>(amount + 1, INT_MAX - 1));

    for (int i = 0; i <= n; i++)
    {
        memo[i][0] = 0;
    }
    for (int j = 0; j <= amount; j++)
    {
        memo[0][j] = INT_MAX - 1;
    }

    for (int j = 1; j <= amount; j++)
    {
        int sum = j % nums[0];
        if (sum == 0)
        {
            memo[1][j] = j / nums[0];
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (nums[i - 1] <= j)
            {
                memo[i][j] = min(memo[i - 1][j], 1 + memo[i][j - nums[i - 1]]);
            }
            else
            {
                memo[i][j] = memo[i - 1][j];
            }
        }
    }

    return memo[n][amount];
}
