#include<bits/stdc++.h>
using namespace std;

/***************************************************************************
	Class for graph node is as follows:
******************************************************************************/
class graphNode
{
	public:
		int data;
	vector<graphNode *> neighbours;
	graphNode()
	{
		data = 0;
		neighbours = vector<graphNode *>();
	}

	graphNode(int val)
	{
		data = val;
		neighbours = vector<graphNode *>();
	}

	graphNode(int val, vector<graphNode *> neighbours)
	{
		data = val;
		this->neighbours = neighbours;
	}
};

void dfs(graphNode *node, graphNode *source, map<int, graphNode*> &visited){
	for(auto neighbor: node->neighbours){
		if(!visited[neighbor->data]){
			graphNode* newNode=new graphNode(neighbor->data);
			visited[neighbor->data]=newNode;
			(source->neighbours).push_back(newNode);
			dfs(neighbor, newNode, visited);
		}else{
			(source->neighbours).push_back(visited[neighbor->data]);
		}
	}
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(!node) return NULL;
	
	map<int, graphNode*> visited;
	
	graphNode *source=new graphNode(node->data);
	visited[node->data]=source;
	
	dfs(node, source, visited);
	
	return source;
}