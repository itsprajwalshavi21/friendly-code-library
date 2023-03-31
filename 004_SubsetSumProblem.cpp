#include <bits/stdc++.h>
using namespace std;

void printDP()
{

}

bool subsetSum(vector<int> arr, int sum)
{
    // int n = arr.size() + 1;
    int **SS = new int *[arr.size() + 1];
    for (int i = 0; i < arr.size() + 1; i++)
    {
        SS[i] = new int[sum + 1];
    }
    
    for (int i = 0; i < sum; i++)
    {
        SS[0][i] = 0;
    }
    for (int i = 0; i < sum; i++)
    {
        SS[i][0] = 1;
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (SS[i - 1][j] == 1)
            {
                SS[i][j] = 1;
            }
            else if (arr[i - 1] > j)
            {
                SS[i][j] = 0;
            }
            else
            {
                SS[i][j] = SS[i - 1][j - arr[i - 1]];
            }
        }
    }
    cout << endl << endl;
    cout << "    " ;
    for (int i = 0; i < sum + 1; i++)
    {
        cout<< i << " ";
    }
    cout << endl;
    cout << "  __" ;
    for (int i = 0; i < sum + 1; i++)
    {
        cout<< "__";
    }
    cout << endl;
    for (int i = 0; i < arr.size() + 1; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < sum + 1; j++)
        {
            cout << SS[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}

int main()
{
    vector<int> arr;
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int val;
    int sum;
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    cout << "Enter the subset sum: ";
    cin >> sum;

    int ret = subsetSum(arr, sum);
    if (ret == 1)
    {
        cout << "Subset exists that can sum to " << sum << endl;
    }
    else
    {
        cout << "No subset exists that can sum to " << sum << endl;
    }
}