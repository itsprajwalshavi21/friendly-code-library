#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> E(V);
    
    for(auto edge: edges){
        E[edge.first].push_back(edge.second);
        E[edge.second].push_back(edge.first);
    }
    
    for(int i=0; i<V; i++){
        sort(E[i].begin(), E[i].end());
    }
    
    vector<bool> visited(V, false);
    vector<int> result;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            queue<int> Q;
            Q.push(i);
            visited[i]=true;
        
            while(!Q.empty()){
                int curr=Q.front(); Q.pop();
                result.push_back(curr);

                for(auto edge: E[curr]){
                    if(!visited[edge]){
                        Q.push(edge);
                        visited[edge]=true;
                    }
                }
            }
        }
    }
    
    return result;
}