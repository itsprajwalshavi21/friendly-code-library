#include<bits/stdc++.h>
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

class BSTiterator
{
	public:
	stack<TreeNode<int> *> S;
	
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
		add(root);
    }

	void add(TreeNode<int> *root){
		if(!root) return;
		
		while(root){
			S.push(root);
			root=root->left;
		}
	}
	
    int next()
    {
        // write your code here
		if(S.empty()){
			return -1;
		}
		
		TreeNode<int> *root=S.top();
		S.pop();
		
		int data=root->data;
		add(root->right);
		return data;
    }

    bool hasNext()
    {
        // write your code here
		return !S.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/