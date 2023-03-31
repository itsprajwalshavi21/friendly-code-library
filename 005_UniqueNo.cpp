#include <bits/stdc++.h>
using namespace std;


/*

From array input, find the unique element

INPUT:
5
1 1 3 2 2

OUTPUT:
3

*/

int main()
{
    int n;
    cin >> n;
    vector <int> v;
    int val;
    int xo = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }
    for (int i = 0; i < n; i++)
    {
        xo ^= v[i];
    }
    cout << "Unique element is: " << xo << endl;
    return 0;
}