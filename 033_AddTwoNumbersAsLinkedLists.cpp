/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/
#include<bits/stdc++.h>
using namespace std;

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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    Node *l1=head1;
    Node *l2=head2;
        
    Node *dummy = new Node(0);
    Node *l3=dummy;
    
    int carry=0;
    
    while(l1 || l2){
        int num1=l1?l1->data:0;
        int num2=l2?l2->data:0;
        int sum=num1+num2+carry;
        
        carry=sum/10;
        sum=sum%10;
        
        Node *n= new Node(sum);
        l3->next=n;
        l3=l3->next;
        
        if(l1){
            l1=l1->next;
        }
        if(l2){
            l2=l2->next;
        }
    }
    
    if(carry>0){
        Node *n= new Node(carry);
        l3->next=n;
        l3=l3->next;
    }
    
    return dummy->next;
}