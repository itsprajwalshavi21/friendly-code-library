#include <bits/stdc++.h>
using namespace std;

void selection_sort(int A[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        swap(A[min], A[i]);
    }
}

int main()
{
    int A[] = {2, 5, 7, 1, 2, 3, 5, 7};
    int n = sizeof(A) / sizeof(int);
    selection_sort(A, n);
    cout << "After Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}