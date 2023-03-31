#include<bits/stdc++.h>
using namespace std;

/*************************************************************
    Following is the LinkedListNode class structure
*************************************************************/
template <typename T>   
class LinkedListNode
{
	public:
	T data;
	LinkedListNode<T> *next;
	LinkedListNode<T> *random;
	LinkedListNode(T data)
	{
		this->data = data;
		this->next = NULL;
	}
};

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *dummy=new LinkedListNode<int>(0);
    LinkedListNode<int> *newHead=dummy;
    LinkedListNode<int> *ptr=head;
    
    map<LinkedListNode<int>*, LinkedListNode<int>*> nodes;
    
    while(ptr){
        LinkedListNode<int> *newNode=new LinkedListNode<int>(ptr->data);
        
        nodes[ptr]=newNode;
        newHead->next=newNode;
        
        ptr=ptr->next;
        newHead=newHead->next;
    }
    
    newHead=dummy->next;
    ptr=head;
    
    while(newHead){
        newHead->random=ptr->random?nodes[ptr->random]:NULL;
        
//         cout<<newHead->data<<" "<<(newHead->random?newHead->random->data:-1)<<" ";
        newHead=newHead->next;
        ptr=ptr->next;
    }
//     cout<<endl;
    
    return dummy->next;
}
