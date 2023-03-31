#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int n, vector<vector<int>> &result, vector<int> &subset, int start){
    if(subset.size()){
        result.push_back(subset);
    }
    
    for(int i=start; i<n; i++){
        subset.push_back(arr[i]);
    	print(arr, n, result, subset, i+1);
        subset.pop_back();
    }
}

vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){
    // Write your code here
	vector<vector<int>> result;
    vector<int> subset;
    
    print(arr, n, result, subset, 0);
    
    return result;
}