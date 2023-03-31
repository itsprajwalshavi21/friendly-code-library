#include <bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the TreeNode class structure
************************************************************/
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

void dfs(TreeNode<int> * root, int X, priority_queue<int> &heap){
	if(!root) return;
	
	if(root->val<=X) heap.push(root->val);
	
	dfs(root->left, X, heap);
	dfs(root->right, X, heap);
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
	priority_queue<int> heap;
	
	dfs(root, X, heap);
	
	return heap.top();
}