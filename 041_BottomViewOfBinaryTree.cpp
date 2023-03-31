#include <bits/stdc++.h>
using namespace std;

/*************************************************************
    Following is the Binary Tree node structure.
*************************************************************/
template <typename T>
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

vector<int> bottomView(BinaryTreeNode<int> * root){
    // Write your code here.
	vector<int> result;
	
	if(!root) return result;
		
	queue<pair<int, BinaryTreeNode<int> *>> Q;
	map<int, BinaryTreeNode<int> *> M;
	Q.push({0, root});
	M[0]=root;
	
	while(!Q.empty()){
		auto it=Q.front();
		Q.pop();
		
		int num=it.first;
		BinaryTreeNode<int> *curr=it.second;
		
		if(curr->left){
			int left=num+1;
			M[left] = curr->left;
			Q.push({left, curr->left});
		}
		if(curr->right){
			int right=num-1;
			M[right] = curr->right;
			Q.push({right, curr->right});
		}
	}
	
	for(auto it: M){
		result.push_back(it.second->data);
	}
	
	reverse(result.begin(), result.end());
	return result;
}
