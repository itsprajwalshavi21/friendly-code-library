#include <bits/stdc++.h>
using namespace std;

/*************************************************************
    Following is the Binary Tree node structure
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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    queue<BinaryTreeNode<int>*> nodes;
    vector<int> result;
    bool LtR=true;
    
    if(!root) return result;
    
    nodes.push(root);
    
    while(!nodes.empty()){
        int k=nodes.size();
        vector<int> temp;
        
        for(int i=0; i<k; i++){
            BinaryTreeNode<int>* node=nodes.front();
            nodes.pop();
            temp.push_back(node->data);
            
            if(node->left){
                nodes.push(node->left);
            }
            if(node->right){
                nodes.push(node->right);
            }
        }
        
        if(!LtR){
            reverse(temp.begin(), temp.end());
        }
        LtR=!LtR;
            
        for(auto num: temp){
            result.push_back(num);
        }
    }
    
    return result;
}
