#include<bits/stdc++.h>
using namespace std;    
    
void solve(vector<int> &V, vector<vector<int>> &result, vector<int> &subset, int start){
    result.push_back(subset);
    
    int n=V.size();
    if(start>=n){
        return;
    }
    
    for(int i=start; i<n; i++){
        subset.push_back(V[i]);
    	solve(V, result, subset, i+1);
        subset.pop_back();
    }
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> result;
    vector<int> subset;
//     result.push_back(subset);
    
    solve(v, result, subset, 0);
    
    return result;
}