/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

int main()
{
    vector <int> A = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(A) << endl;
    return 0;
}