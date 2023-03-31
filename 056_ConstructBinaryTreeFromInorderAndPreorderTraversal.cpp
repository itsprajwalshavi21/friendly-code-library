#include <bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the TreeNode class structure
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

TreeNode<int> *buildTree(vector<int> &inorder, int is, int ie, vector<int> &preorder, int &rootIndex){
    if(is>ie) return NULL;
    
    int pos=is;
    while(inorder[pos] != preorder[rootIndex]) pos++;
    
    TreeNode<int>* node = new TreeNode<int>(inorder[pos]);
    rootIndex++;
    
    node->left=buildTree(inorder, is, pos-1, preorder, rootIndex);
    node->right=buildTree(inorder, pos+1, ie, preorder, rootIndex);
    
    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int rootIndex=0;
    return buildTree(inorder, 0, inorder.size()-1, preorder, rootIndex);
}