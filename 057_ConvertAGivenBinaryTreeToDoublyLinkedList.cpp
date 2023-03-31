#include <bits/stdc++.h>
using namespace std;

/*************************************************************
    Following is the Binary Tree node structure
*************************************************************/

template <typename T >
class BinaryTreeNode 
{
public : 
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data) {
		this -> data = data;
		left = NULL;
		right = NULL;
	}
};

void inorder(BinaryTreeNode<int>* root, vector<int> &ans){
	if(!root) return;
	
	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
	vector<int> ans;
	inorder(root, ans);
	
	BinaryTreeNode<int>* dummy = new BinaryTreeNode<int>(0);
	BinaryTreeNode<int>* head=dummy;;
	
	for(int i=0; i<ans.size(); i++){
		BinaryTreeNode<int>* node = new BinaryTreeNode<int>(ans[i]);

		head->right = node;
		node->left = head;

		head=head->right;
	}
	
	return dummy->right;
}