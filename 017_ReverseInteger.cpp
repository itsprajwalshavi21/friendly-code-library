#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int negative = 0, len, tmp;
    
    if (x > 0) {
        if (x < INT_MAX-1) {}
        else {return 0;}
    }
    else {
        if (x > INT_MIN+1) {}
        else {return 0;}
    }

	if (x < 0) {
		negative = 1;
		x = -x;
	}
  	/* convert int to string */
	char str[1000];
	sprintf(str, "%d", x);
	len = strlen(str);

	if (x < 0) {
		negative = 1;
		x = -x;
	}

	for (int i=0; i<len/2; i++) {
		tmp = str[len-1-i];
		str[len-1-i] = str[i];
		str[i] = tmp;
	}
	long long retval = strtol(str, (char**) NULL, 10);
    if (retval > 0) {
        if (retval < INT_MAX-1) {}
        else {return 0;}
    }
    else {
        if (retval > INT_MIN+1) {}
        else {return 0;}
    }
	if (negative == 1) {retval = -retval;}
    
	return (int) retval;
}

int main()
{
    int n;
    cin >> n;
    cout << reverse(n);
    return 0;
}