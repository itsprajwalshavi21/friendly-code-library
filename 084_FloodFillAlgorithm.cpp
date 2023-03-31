#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &image, int m, int n, int i, int j, int K, int newColor, vector<vector<bool>> &visited){
	if(i<0 || i>=m || j<0 || j>=n || image[i][j]!=K || visited[i][j]){
		return;
	}
	
	image[i][j]=newColor;
	visited[i][j]=true;
	
	bfs(image, m, n, i+1, j, K, newColor, visited);
	bfs(image, m, n, i-1, j, K, newColor, visited);
	bfs(image, m, n, i, j+1, K, newColor, visited);
	bfs(image, m, n, i, j-1, K, newColor, visited);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
	int K=image[x][y];
	int m=image.size(), n=image[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	
	bfs(image, m, n, x, y, K, newColor, visited);
	
	return image;
}