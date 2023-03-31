// not there in code studio.. will be used in Kruskal's Algo

#include <bits/stdc++.h>
using namespace std;

const int n = 1000000;
int parent[n];
int rankOf[n];

void makeSet(){
	for (int i = 1; i < n; i++){
		parent[i] = i;
		rankOf[i] = 0;
	}
}

int findParent(int node){
	if(node == parent[node]){
		return node;
	}

	return parent[node] = findParent(parent[node]);
}

void makeUnion(int u, int v){
	u = findParent(u);
	v = findParent(v);

	if(rankOf[u] < rankOf[v]){
		parent[u] = v;
	}else if(rankOf[v] < rankOf[u]){
		parent[v] = u;
	}else{
		parent[v] = u;
		rankOf[u]++;
	}
}

void main(){
	makeSet();

	int m;
	while(m--){
		int u, v;
		makeUnion(u, v);
	}

	// to check whether two nodes belongs to same components or not
	if(findParent(2) != findParent(3)){
		cout << "Different Component";
	}else{
		cout << "Same Component";
	}
}