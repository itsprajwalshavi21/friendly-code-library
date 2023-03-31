/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
#include <bits/stdc++.h>
using namespace std;

class Node {
	public :

	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		this -> next = NULL;
	}
};

Node *removeLoop(Node *head)
{
    // Write your code here.
    map<Node*, bool> hash;
    Node* ptr=head;
    
    while(ptr){
        if(hash[ptr->next]){
            ptr->next=NULL;
            break;
        }
        hash[ptr]=true;
        ptr=ptr->next;
    }
    
    return head;
}