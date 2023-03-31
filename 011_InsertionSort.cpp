#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = A[i];
        int j = i;
        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
            j = j - 1;
        }
        A[j] = temp;
    }
}

int main()
{
    int A[] = {2, 5, 7, 1, 2, 3, 5, 7};
    int n = sizeof(A) / sizeof(int);
    insertion_sort(A, n);
    cout << "After Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}