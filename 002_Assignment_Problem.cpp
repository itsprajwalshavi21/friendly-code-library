#include <bits/stdc++.h>
using namespace std;

void printMatrix(int jobs, int **cost)
{
    for (int i = 0; i < jobs; i++)
    {
        for (int j = 0; j < jobs; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

// ? Function to count set no of bits in a number
/*
EG: 5 in binary is [1 0 1]
So, set number of bits are 2
*/
int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int assignmentProblem(int N, int **cost)
{
    int size = pow(2, N);
    int dp[size];
    // Initialize all values to infinity (INT_MAX)
    for (int i = 0; i < size; i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
    for (int mask = 0; mask < size; mask++)
    {
        int x = countSetBits(mask);
        for (int j = 0; j < N; j++)
        {
            // Condition to check if jth bit of a number is ser or no
            /*
            eg: 5 in binary is [1 0 1]
                                | | |
                                v v v
                            j = 2 1 0
                If we check if j bit of 5 is set (j = 0), It is set
                lly, when j = 1, It is not set,
                    j = 2, Its is set
            */
            if (!((mask >> j) & 1))
            {
                dp[mask | 1 << j] = min(dp[mask | 1 << j], dp[mask] + cost[x][j]);
            }
        }
        // printArray(dp,size);
    }
    return dp[size - 1];
}

int main()
{
    int jobs;
    cout << "Enter no of jobs: ";
    cin >> jobs;
    int **cost = new int *[jobs];

    for (int i = 0; i < jobs; i++)
    {
        cost[i] = new int[jobs];
    }

    int temp;
    cout << "Enter cost for (jobs * jobs) :" << endl;
    for (int i = 0; i < jobs; i++)
    {
        for (int j = 0; j < jobs; j++)
        {
            cin >> cost[i][j];
        }
    }
    // printMatrix(jobs, cost);
    cout << "All jobs can be completed with min cost of: " << assignmentProblem(jobs, cost);

    return 0;
}