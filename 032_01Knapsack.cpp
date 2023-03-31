#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	int t[n+1][w+1];
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=w; j++){
			if(i==0 || j==0){
				t[i][j]=0;
			}else{
				if(j >= weights[i-1]){
					t[i][j] = max(t[i-1][j], t[i-1][j-weights[i-1]]+values[i-1]);
				}else{
					t[i][j] = t[i-1][j];
				}
			}
		}
	}
	
	return t[n][w];
}