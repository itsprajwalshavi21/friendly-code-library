#include<bits/stdc++.h>
using namespace std;

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	int maxSum=INT_MIN;
	vector<int> sum(n, 0);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(rack[i]>rack[j]){
				sum[i]=max(sum[i], sum[j]+rack[i]);
			}
		}
		sum[i]=max(sum[i], rack[i]);
		maxSum=max(maxSum, sum[i]);
	}
	
	return maxSum;
}