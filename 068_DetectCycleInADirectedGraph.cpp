#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &dfs_visited){
	visited[node]=true;
	dfs_visited[node]=true;
	
	for(auto edge: adj[node]){
		if(!visited[edge]){
			if(checkForCycle(edge, node, adj, visited, dfs_visited)) return true;
		}else{
			if(dfs_visited[edge]){
				return true;
			}
		}
	}
	
	dfs_visited[node]=false;
	return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
	vector<vector<int>> adj(n+1);
	
	for(auto edge: edges){
		adj[edge.first].push_back(edge.second);
	}
	
	vector<bool> visited(n+1, false);
	vector<bool> dfs_visited(n+1, false);
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			if(checkForCycle(i, -1, adj, visited, dfs_visited)) return 1;
		}
	}
	
	return 0;
}

