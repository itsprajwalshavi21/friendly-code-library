#include <bits/stdc++.h>
using namespace std;

bool wordBreak(vector < string > & arr, int N, string & target) {
    // Write your code here.
	int n=target.length();
	vector<bool> dp(n+1, false);
	dp[n]=true;
	
	for(int i=n-1; i>=0; i--){
		for(auto str: arr){
			if(i+str.length()<=n && str==target.substr(i, str.length())){
				dp[i]=dp[i+str.length()];
			}
			if(dp[i]){
				break;
			}
		}
	}
	
	return dp[0];
}