#include<bits/stdc++.h>
using namespace std;

/************************************************************
    Following is the linked list node structure:
************************************************************/

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		this->data = data;
	}
};

Node<int>* reverseLL(Node<int>* head){
	Node<int>* curr=head;
    Node<int>* prev=NULL;
    
    while(head){
        curr=head;
        head=head->next;
        curr->next=prev;
        prev=curr;
    }
    
    head=curr;
    return head;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here.
    first=reverseLL(first);
    second=reverseLL(second);
    
    Node<int>* dummy=new Node<int>(0);
    Node<int>* head=dummy;
    
    int carry=0;
    
    while(first || second){
        int num1=first?first->data:0;
        int num2=second?second->data:0;
        
        int sum=num1+num2+carry;
        
        carry=sum/10;
        sum%=10;
        
        Node<int>* newNode= new Node<int>(sum);
        head->next=newNode;
        head=head->next;
        
        if(first){
        	first=first->next;   
        }
        
        if(second){
        	second=second->next;   
        }
    }
    
    if(carry){
        Node<int>* newNode= new Node<int>(carry);
        head->next=newNode;
        head=head->next;
    }
    
    return reverseLL(dummy->next);;
}