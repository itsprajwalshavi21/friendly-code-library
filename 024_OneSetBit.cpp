/*
Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/

#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n &= n - 1;
    }
    return count;
}

int main()
{
    int n = 00000000000000000000000000001011;
    cout << hammingWeight(n);
    return 0;
}