#include <bits/stdc++.h>
using namespace std;

/*
Find maximum XOR value for two combination between two ranges.

INPUT:
10 15

OUTPUT:
7

Explanation:
XOR of
Max of: (10,11),(10,12),(10,13),(10,14),(10,15),(11,12),(11,13),.....
*/

int main()
{
    int r, l;
    cin >> r >> l;
    int com = r ^ l;
    int count = 1;
    while (com != 0)
    {
        com = com >> 1;
        count = count << 1;
    }
    cout << "Maximum XOR value of " << r << " and " << l << " is: " << count - 1;
    return 0;
}