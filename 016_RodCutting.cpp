/*
Cutting a rod into n parts so that the product is maximum
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n;
    if (n % 2 == 0)
    {
        p = (n / 2) * (n / 2);
    }
    else
    {
        p = (n / 2) * ((n / 2) + 1);
    }
    cout << p;
    return 0;
}
