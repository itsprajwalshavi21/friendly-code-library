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

int findDiameter(TreeNode<int> *root, int &result){
    if(!root){
        return 0;
    }
    
    
    int left=findDiameter(root->left, result);
    int right=findDiameter(root->right, result);
    
    int temp=1+max(left, right);
    int ans=1+left+right;
    result=max(result, ans);
    
    return temp;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(!root){
        return 0;
    }
    
	int result=0;
    
    cout<<root->data<<endl;
    findDiameter(root, result);
    
    return result;
}
