#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int A[], int n)
{
    int temp;
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < n - k - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {2, 5, 7, 1, 2, 3, 5, 7};
    int n = sizeof(A) / sizeof(int);
    bubble_sort(A, n);
    cout << "After Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}