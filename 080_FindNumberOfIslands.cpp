#include<bits/stdc++.h>
using namespace std;

void bfs(int** arr, int n, int m, int i, int j){
	if(i<0 || i>=n || j<0 || j>=m || arr[i][j]==0){
		return;
	}
	
	arr[i][j]=0;
	
	bfs(arr, n, m, i+1, j);
	bfs(arr, n, m, i-1, j);
	bfs(arr, n, m, i, j+1);
	bfs(arr, n, m, i, j-1);
	
	bfs(arr, n, m, i-1, j-1);
	bfs(arr, n, m, i+1, j-1);
	bfs(arr, n, m, i-1, j+1);
	bfs(arr, n, m, i+1, j+1);
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
	int count=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j]==1){
				count++;
				bfs(arr, n, m, i, j);
			}
		}
	}
	
	return count;
}
