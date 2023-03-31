#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited){
	visited[node]=true;
	
	for(auto edge: adj[node]){
		if(!visited[edge]){
			if(checkForCycle(edge, node, adj, visited)) return true;
		}else{
			if(edge != parent){
				return true;
			}
		}
	}
	
	return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
	vector<vector<int>> adj(n+1);
	
	for(auto edge: edges){
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	
	vector<bool> visited(n+1, false);
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			if(checkForCycle(i, -1, adj, visited)) return "Yes";
		}
	}
	
	return "No";
}
