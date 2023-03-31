#include<bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the LinkedListNode class:
*****************************************************************/

template <typename T>
class LinkedListNode
{
public:
	T data;
	LinkedListNode<T> *next;
	LinkedListNode(T data)
	{
		this->data = data;
		this->next = NULL;
	}
};

LinkedListNode<int>* reverseLL(LinkedListNode<int>* head){
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    
    while(head){
        curr=head;
        head=head->next;
        curr->next=prev;
        prev=curr;
    }
    
    return head=curr;
}

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(!head || !K) return head;
    
    head=reverseLL(head);
    
    if(K==1){
        head=head->next;
    }else{
        LinkedListNode<int>* prev=NULL;
        LinkedListNode<int>* curr=head;
        while(--K && curr){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        delete curr;    
    }
    
    head=reverseLL(head);
    
    return head;
}