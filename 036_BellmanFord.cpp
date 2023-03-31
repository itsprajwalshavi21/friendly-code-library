#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int V, int E, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
	vector<vector<int>> graph(V+1, vector<int>(V+1, 1000000000));
	for(int i=0; i<E; i++){
		graph[edges[i][0]][edges[i][1]]=edges[i][2];
	}
	for(int i=1;i<=V;i++){
		graph[i][i]=0;
	}
	
// 	for(auto row: graph){
// 		for(auto col: row){
// 			cout<<col<<" ";
// 		}
// 		cout<<endl;
// 	}
	
	for(int k=1; k<=V; k++){
		for(int i=1; i<=V; i++){
			for(int j=1; j<=V; j++){
				if(i!=j && graph[i][k]!=1000000000 && graph[k][j]!=1000000000)
					graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}	
	}
	
	return graph[src][dest];
}