/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
*/

#include <bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i <= nums.size(); i++)
    {
        if (i + 2 < nums.size() && nums[i + 1] + nums[i + 2] > nums[i])
        {
            return nums[i + 1] + nums[i + 2] + nums[i];
        }
    }
    return 0;
}

int main()
{
    vector<int> nums = {2, 1, 2};
    cout << largestPerimeter(nums) << endl;
    return 0;
}