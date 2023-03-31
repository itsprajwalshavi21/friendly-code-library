#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] < key)
        {
            low = mid + 1;
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1; // key not found
}

int main()
{
    int a[] = {1, 5, 7, 8, 9, 2, 3, 12};
    int n = sizeof(a) / sizeof(int);
    int key = 5;
    cout << "Found at index: " << binarySearch(a, 0, n, key);
    return 0;
}