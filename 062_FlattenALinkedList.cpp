#include<bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the Node class:
*****************************************************************/

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* merge(Node* L1, Node* L2) {
    if(!L1){
        return L2;
    }
    if(!L2){
        return L1;
    }
    
    Node* result;
    if(L1->data<L2->data){
        result=L1;
        result->child=merge(L1->child, L2);
    }else{
        result=L2;
        result->child=merge(L1, L2->child);
    }
    
    result->next=NULL;
    
    return result;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(!head || !head->next){
        return head;
    }
    
    return merge(head, flattenLinkedList(head->next));
    
//     Method-2 (gives TLE)
    Node* curr=head;
    vector<int> values;
    
    while(curr){
        values.push_back(curr->data);
        
        if(curr->next){
            Node* child=curr->child;
            curr->child=curr->next;
            
            Node* ptr=curr->child;
            while(ptr->child){
                ptr=ptr->child;
            }
            ptr->child=child;
            
            curr->next=NULL;
        }
        
        curr=curr->child;
    }
    
    sort(values.begin(), values.end());
    
   	curr=head;
    int i=0;
    while(curr){
        curr->data=values[i++];
        curr=curr->child;
    }
    
    return head;
}
