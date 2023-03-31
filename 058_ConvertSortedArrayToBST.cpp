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

TreeNode<int>* buildTree(vector<int> &arr, int left, int right){
    if(left>right) return NULL;
    
    int mid= (left+right)/2;
    
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);
    
    node->left=buildTree(arr, left, mid-1);
    node->right=buildTree(arr, mid+1, right);
    
    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if(!n) return NULL;
    
    return buildTree(arr, 0, n-1);
}