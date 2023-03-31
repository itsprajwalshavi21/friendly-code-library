#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &output, int node, vector<bool> &visited){
	output.push_back(node);
	visited[node]=true;
	
	for(auto adj: graph[node]){
		if(!visited[adj]){
			dfs(graph, output, adj, visited);
		}
	}
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
	vector<vector<int>> graph(V);
	for(int i=0;i<E; i++){
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}
	
	vector<vector<int>> DFS;
	vector<bool> visited(V, false);
	
	for(int i=0; i<V; i++){
		if(!visited[i]){
			vector<int> output;
			dfs(graph, output, i, visited);
			DFS.push_back(output);
		}
	}
	
	return DFS;
}