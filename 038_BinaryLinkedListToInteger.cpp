/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
		
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

int binaryToInteger(int n, Node *head) {
    //    Write your code here
    Node *temp = head;
    int num = 0;
//     for(int i=n-1; i>=0 && temp; i--){
//         int curr= pow(2, i) * temp->data;
//         num += curr;
//         temp = temp->next;
//     }
    while (head != NULL) {
        num *= 2;
        num += head->data;

        // Move to the next node.
        head = head->next;
    }
    
    return num;
}