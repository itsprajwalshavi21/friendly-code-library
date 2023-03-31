/*
Task is to calculate the number of trailing zeros in the factorial n!
For example, 20!2432902008176640000 and it has 4 trailing zeros.
*/

#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    int sum = 0;
    int count = 0;
    while (n != 0)
    {
        sum += n / 5;
        n /= 5;
    }
    cout << sum << endl;
    return 0;
}