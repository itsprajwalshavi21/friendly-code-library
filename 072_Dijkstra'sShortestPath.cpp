#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int source) {
    // Write your code here.
	vector<int> D(V, INT_MAX);
	D[0]=0;
	
	vector<vector<pair<int, int>>> graph(V);
	for(auto row: vec){
		graph[row[0]].push_back({row[1], row[2]});
		graph[row[1]].push_back({row[0], row[2]});
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
	PQ.push({0, source}); //distance->destination
	
	while(!PQ.empty()){
		int u=PQ.top().second;
		PQ.pop();
		
		for(auto it: graph[u]){
			int v=it.first, w=it.second;
			if(D[u] + w < D[v]){
				D[v]=w+D[u];
				PQ.push({D[v], v});
			}
		}
	}
	
	return D;
}
