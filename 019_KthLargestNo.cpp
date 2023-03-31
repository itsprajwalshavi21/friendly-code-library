/*
Given an integer array nums and an integer k, return the kth largest element in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(int *nums, int numsSize, int k)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize - i - 1; j++)
        {
            if (nums[j] < nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    return nums[k - 1];
}

int main()
{
    int A[] = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int n = sizeof(A) / sizeof(int);
    cout << findKthLargest(A, n, k);
    return 0;
}