#include <bits/stdc++.h>
using namespace std;

/************************************************************
   Following is the TreeNode class structure   
************************************************************/

template <typename T>
class TreeNode{ 
public:
	T data; 
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T data) 
	{ 
		this -> data = data; 
		left = NULL; 
		right = NULL; 
	}
};
   
TreeNode<int>* createTree(vector<int>& inorder, int inorderStart, int inorderEnd, vector<int>& postorder, int postorderStart, int postorderEnd) {
	if(postorderStart > postorderEnd){
		return NULL;
	}

	TreeNode<int>* node=new TreeNode<int>(postorder[postorderEnd]);

	int pos;
	for(int i=inorderStart;i<=inorderEnd;i++){
		if(node->data == inorder[i]){
			pos=i;
			break;
		}
	}

	int numsLeft=pos-inorderStart;

	node->left=createTree(inorder, inorderStart, pos-1, postorder, postorderStart, postorderStart+numsLeft-1);

	node->right=createTree(inorder, pos+1, inorderEnd, postorder, postorderStart+numsLeft, postorderEnd-1);

	return node;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
        return createTree(inOrder, 0, inOrder.size()-1, postOrder, 0, postOrder.size()-1);
}
