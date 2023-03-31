/*
Print nth row of a pascals triangle
*/

#include <bits/stdc++.h>
using namespace std;

void getRow(int rowIndex)
{
    vector<vector<int>> v;
    rowIndex++;
    for (int i = 0; i < rowIndex; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i + 1; j++)
        {
            temp.push_back(1);
        }
        v.push_back(temp);
    }
    // if(rowIndex > 2)
    {
        for (int i = 2; i < v.size(); i++)
        {
            for (int j = 1; j < v[i].size() - 1; j++)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
    }
    for (int i = 0; i < v[rowIndex - 1].size(); i++)
    {
        cout << v[rowIndex - 1][i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    getRow(n);
    return 0;
}