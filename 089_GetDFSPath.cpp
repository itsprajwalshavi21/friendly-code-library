#include<bits/stdc++.h>
using namespace std;

map<int, vector<int>> edges;
vector<int> path;

bool dfs(int e, vector<int> &subset, vector<bool> &visited, int v2){
    if(e==v2){
        path=vector<int>(subset);
        return true;
    }
    
    if(visited[e]){
        return false;
    }
    
    visited[e]=true;
    
    for(auto E: edges[e]){
        subset.push_back(E);
        bool flag = dfs(E, subset, visited, v2);
        
        if(flag){
            return true;
        }
        
        subset.pop_back();
	}
    
    return false;
}

vector<int> getPath(int V, int E, vector<int> a, vector<int> b, int v1, int v2) {
    //    Write your code here
    for(int i=0; i<V; i++){
        edges[i]={};
    }
    
    for(int i=0; i<a.size(); i++){
        edges[a[i]].push_back(b[i]);
        edges[b[i]].push_back(a[i]);
    }
    
    vector<int> subset;
    subset.push_back(v1);
    vector<bool> visited(V, false);
    
    for(auto E: edges[v1]){
        visited=vector<bool>(V, false);
        visited[v1]=true;
        
        subset.push_back(E);
        bool flag=dfs(E, subset, visited, v2);
        
        if(flag){
            reverse(path.begin(), path.end());
//             for(auto p:path){
//                 cout<<p<<" ";
//             }
//             cout<<endl;
            return path;
        }
        
        subset.pop_back();
    }
    
    return {};
}