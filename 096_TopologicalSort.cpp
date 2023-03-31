#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
	vector<int> result(v);
	stack<int> S;
	vector<int> in(v, 0);
	int order=0;
	
	vector<vector<int>> adj(v);
	for(auto edge: edges){
		adj[edge[0]].push_back(edge[1]);
		in[edge[1]]++;
	}
	
	for(int i=0; i<v; i++){
		if(in[i]==0){
			S.push(i);
		}
	}
	
	while(!S.empty()){
		int u=S.top(); S.pop();

		result[order++]=u;

		for(auto v: adj[u]){
			if(--in[v] == 0){
				S.push(v);
			}
		}
	}
	
	return result;
}	