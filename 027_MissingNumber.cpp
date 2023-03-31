/*
You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    int arr[n];
    for (long long int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    long long int sum = (n * (n + 1)) / 2;
    for (long long int i = 0; i < n - 1; i++)
    {
        sum -= arr[i];
    }
    cout << sum << endl;
    return 0;
}