#include<bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the Node class:
*****************************************************************/
class Node
{
	public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *firstNode(Node *head)
{
	//    Write your code here.
	Node *slow=head;
	Node *fast=head;
	
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		
		if(slow==fast){
			Node *entry=head;
			
			while(entry!=slow){
				slow=slow->next;
				entry=entry->next;
			}
			
			return entry;
		}
	}
	
	return NULL;
}