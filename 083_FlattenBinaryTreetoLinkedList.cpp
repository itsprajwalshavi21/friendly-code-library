#include <bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the TreeNode class structure.
************************************************************/

template <typename T>
class TreeNode {
	public:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};


void dfs(TreeNode<int> *root,vector<TreeNode<int> *> &pre){
	if(!root) return;
	
	pre.push_back(root);
	dfs(root->left, pre);
	dfs(root->right, pre);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
	vector<TreeNode<int> *> pre;
	dfs(root, pre);
	
	for(int i=0; i<pre.size()-1; i++){
		pre[i]->right=pre[i+1];
		pre[i]->left=NULL;
	}
	
	return pre[0];
}