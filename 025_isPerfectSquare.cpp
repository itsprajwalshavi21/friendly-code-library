/*
Given an integer n, return true if it is a power of two. Otherwise, return false.
*/
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 1)
    {
        return 1;
    }
    for (int i = 0; i < 31; i++)
    {
        if ((2 << i) <= n)
        {
            if ((2 << i) == n)
            {
                return 1;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;
}