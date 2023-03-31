#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int start, int mid, int end)
{
    int p = start, q = mid + 1;
    int Arr[end - start + 1], k = 0;
    for (int i = start; i <= end; i++)
    {
        if (p > mid) // checks if first part comes to an end or not .
            Arr[k++] = A[q++];

        else if (q > end) // checks if second part comes to an end or not
            Arr[k++] = A[p++];

        else if (A[p] < A[q]) // checks which part has smaller element.
            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }
    for (int p = 0; p < k; p++)
    {
        A[start++] = Arr[p];
    }
}
void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2; // defines the current array in 2 parts .
        merge_sort(A, start, mid);   // sort the 1st part of array .
        merge_sort(A, mid + 1, end); // sort the 2nd part of array.

        // merge the both parts by comparing elements of both the parts.
        merge(A, start, mid, end);
    }
}

int main()
{
    int A[] = {2, 5, 7, 1, 2, 3, 5, 7};
    int n = sizeof(A) / sizeof(int);
    merge_sort(A, 0, n);
    cout << "After Sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}