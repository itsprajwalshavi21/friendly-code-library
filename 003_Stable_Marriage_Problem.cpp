#include <bits/stdc++.h>
using namespace std;

/*
? No of test cases:
2
? The number of marriages to find
4
? Woman's preferences: ith line contains the number i 
1 4 3 1 2
2 2 1 3 4
3 1 3 4 2
4 4 3 1 2
? Men's preferences: ith line contains the number i 
1 3 2 4 1
2 2 3 1 4
3 3 1 2 4
4 3 2 4 1
7
1 3 4 2 1 6 7 5
2 6 4 2 3 5 1 7
3 6 3 5 7 2 4 1
4 1 6 3 2 4 7 5
5 1 6 5 3 4 7 2
6 1 7 3 4 5 6 2
7 5 6 2 4 3 7 1
1 4 5 3 7 2 6 1
2 5 6 4 7 3 2 1
3 1 6 5 4 3 7 2
4 3 5 6 7 2 4 1
5 1 7 6 4 3 5 2
6 6 3 7 5 2 4 1
7 1 7 4 2 6 5 3
*/

bool curPreferred(vector<vector<int>> &prefer, int w, int b, int m)
{
    for (int i = 0; i < prefer[0].size(); i++)
    {
        if (prefer[w][i] == b)
            return false;

        if (prefer[w][i] == m)
            return true;
    }
    return false;
}
void solve()
{
    int n, x;
    cout << "Enter N: " ; 
    cin >> n;

    vector<vector<int>> prefer((2 * n), vector<int>(n));

    for (int i = 0; i < (2 * n); i++)
    {
        cin >> x;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            prefer[i][j] = x;
        }
    }

    vector<int> women(n + 1, -1), mfree(n + 1, true);

    int remainMen = n;

    while (remainMen > 0)
    {
        int m;
        for (m = 1; m <= n; m++)
        {
            if (mfree[m] == true)
                break;
        }
        for (int i = 0; i < n && (mfree[m] == true); i++)
        {
            int w = prefer[m + n - 1][i];

            if (women[w] == -1)
            {
                women[w] = m;
                remainMen--;
                mfree[m] = false;
            }
            else
            {
                int mb = women[w];
                if (curPreferred(prefer, w - 1, mb, m))
                {
                    women[w] = m;
                    mfree[m] = false;
                    mfree[mb] = true;
                }
            }
        }
    }
    vector<int> men(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {

        men[women[i]] = i;
    }
    
    cout << "Matches: "<< endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << men[i] << endl;
    }
}

int main()
{
    int t;
    cout << "Enter t: ";
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}