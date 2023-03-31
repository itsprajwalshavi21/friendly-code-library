#include <bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the TreeNode class structure:
************************************************************/
template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
	
	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
	
	~BinaryTreeNode() {
		if (left) {
			delete left;
		}
		if (right) {
			delete right;
		}
	}
};

void inorder(BinaryTreeNode<int>* root, vector<int> &nums) {
    if(!root) return;
    
    inorder(root->left, nums);
    nums.push_back(root->data);
    inorder(root->right, nums);
}

int findCeil(BinaryTreeNode<int> *root, int key){
    // Write your code here.
    if(!root) return -1;
    
    // Write your code here.
//     method-1
    	int ceil=-1;
    while(root){
        if(root->data==key){
            return key;
        }
        
        if(key > root->data){
            root=root->right;
        }else{
            ceil=root->data;
            root=root->left;
        }
    }
    
    return ceil;
    
//     Method-2
//     vector<int> nums;
    
// 	inorder(root, nums);
    
//     if(binary_search(nums.begin(), nums.end(), x)) return x;
    
//     if(nums.back()<x) return -1;
    
//     return *upper_bound(nums.begin(), nums.end(), x);
}