#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int key, data;
		Node *prev;
		Node *next;

		Node(int _key, int _data){
// 		cout<<_key<<" ->"<<_data<<endl;
			data=_data;
			key=_key;
			next=NULL;
			prev=NULL;
		}
};

class LRUCache
{
public:
	int capacity;
	Node *head=new Node(0, 0);
	Node *tail=new Node(0, 0);
	map<int, Node*> hashMap;
	
    LRUCache(int capacity)
    {
        // Write your code here
		this->capacity=capacity;
		
		head->next=tail;
		tail->prev=head;
    }
	
	void createNode(Node *node){
		Node *temp=head->next;
		
		node->next=temp;
		node->prev=head;
		temp->prev=node;
		head->next=node;
	}
	
	void deleteNode(Node* node){
		node->next->prev=node->prev;
		node->prev->next=node->next;
	}

    int get(int key)
    {
        // Write your code here
		if(hashMap.find(key) != hashMap.end()){
			Node* node=hashMap[key];
			int value=node->data;
			
			deleteNode(node);
			hashMap.erase(key);
			
			createNode(node);
			hashMap[key]=node;
			
			return value;
		}
		
		return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
		if(hashMap.find(key) != hashMap.end()){
			Node* node=hashMap[key];
			
			deleteNode(node);
			hashMap.erase(key);
		}
		
		if(hashMap.size()==capacity){
			Node* node=tail->prev;
			
			deleteNode(node);
			hashMap.erase(node->key);
		}
					
		Node *node=new Node(key, value);
		createNode(node);
		hashMap[key]=head->next;
    }
};
