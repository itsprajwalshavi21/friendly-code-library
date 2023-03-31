#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int n, set<vector<int>> &result, vector<int> &subset, int target, int start){
	if(subset.size()){
		if(target==0){
			result.insert(subset);
		}
	}
	
	if(start==n) return;
	
	for(int i=start; i<n; i++){
		if(i>start && arr[i]==arr[i-1]) continue;
		
		subset.push_back(arr[i]);
		solve(arr, n, result, subset, target-arr[i], i+1);
		subset.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	
	set<vector<int>> result;
	vector<int> subset;
	
	solve(arr, n, result, subset, target, 0);
	
	return vector<vector<int>>(result.begin(), result.end());
}
