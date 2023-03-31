#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start]; // make the first element as pivot element.
    for (int j = start + 1; j <= end; j++)
    {
        /*rearrange the array by putting elements which are less than pivot
           on one side and which are greater that on other. */

        if (A[j] < piv)
        {
            swap(A[i], A[j]);
            i += 1;
        }
    }
    swap(A[start], A[i - 1]); // put the pivot element in its proper place.
    return i - 1;             // return the position of the pivot
}

void quick_sort(int A[], int start, int end)
{
    if (start < end)
    {
        // stores the position of pivot element
        int piv_pos = partition(A, start, end);
        quick_sort(A, start, piv_pos - 1); // sorts the left side of pivot.
        quick_sort(A, piv_pos + 1, end);   // sorts the right side of pivot.
    }
}

int main()
{
    int A[] = {2, 5, 7, 1, 2, 3, 5, 7};
    int n = sizeof(A) / sizeof(int);
    quick_sort(A, 0, n);
    cout << "After Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}