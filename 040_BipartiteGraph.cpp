#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &edges, int node, vector<int> &color){
	if(color[node]==-1){
		color[node]=1;
	}
	
	for(int i=0; i<edges[node].size(); i++){
		if(edges[node][i]==1){
			if(color[i]==-1){
				color[i]=1-color[node];
				
				if(!dfs(edges, i, color)){
					return false;
				}
			}
			else if(color[i]==color[node]){
				return false;
			}
		}
	}
	
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	vector<int> color(n, -1);
	
	for(int i=0; i<n; i++){
		if(color[i]==-1){
			if(!dfs(edges, i, color)){
				return false;
			}
		}
	}
			   
	return true;
}