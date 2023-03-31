#include <bits/stdc++.h>
using namespace std;

void generate(int numRows)
{
    vector<vector<int>> v;
    vector<int> temp;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            temp.push_back(1);
        }
        v.push_back(temp);
        temp.clear();
    }
    if (numRows > 2)
    {
        for (int i = 2; i < numRows; i++)
        {
            for (int j = 1; j < i; j++)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    int n;
    cin >> n;
    generate(n);
    return 0;
}