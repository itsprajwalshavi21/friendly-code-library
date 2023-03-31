#include<bits/stdc++.h>
using namespace std;

/*
    ----------------- Binary Tree node class for reference -----------------
*/

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
// 	method-1
	queue<BinaryTreeNode< int > *> Q;
	Q.push(root);
	
	while(!Q.empty()){
		int k=Q.size();
		vector<BinaryTreeNode< int >*> temp;
		
		for(int i=0; i<k; i++){
			BinaryTreeNode< int > *curr=Q.front();
			Q.pop();
			
			if(curr->left){
				Q.push(curr->left);
				temp.push_back(curr->left);
			}
			
			if(curr->right){
				Q.push(curr->right);
				temp.push_back(curr->right);
			}
		}
		
		int n=temp.size();
		
		for(int i=0;i<n-1; i++){
			temp[i]->next=temp[i+1];
		}
	}
}