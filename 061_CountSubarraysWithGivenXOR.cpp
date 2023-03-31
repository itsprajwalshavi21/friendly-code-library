#include<bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
	int n=arr.size();
	int count=0;

	for(int i=0; i<n; i++){
		int ans=arr[i];
		if(ans==x) count++;
		for(int j=i+1; j<n; j++){
			ans^=arr[j];
			if(ans==x) count++;
		}
	}
	
	return count;
}