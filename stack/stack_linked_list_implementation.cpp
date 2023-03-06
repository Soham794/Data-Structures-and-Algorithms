#include <bits/stdc++.h>

using namespace std;

#define nline "\n"
#define space " "

typedef long long int ll;
typedef unsigned long long ull;

struct Node{
	int data;
	Node* next;
};

Node* top = NULL;

bool isEmpty(){
	if(top == NULL){ return true;}
	return false;
}

void push(int val){

	Node* newnode = new Node;
	newnode->data = val;
	newnode->next = top;
	

	top = newnode;

}

void pop(){

	Node* temp = top;
	
	if(top == NULL){ return;}

	top = top->next;
	// free(temp);aaa
	delete temp;

}

void print(){

	cout << "stack : "; 

	Node* temp=top;
	while(temp!=NULL){
		cout << temp->data << space;
		temp=temp->next;
	}

	cout << nline;
}

void peek(){
	
	if(top == NULL) { cout << "NULL" << nline;}
	cout << top->data << nline;

}

int Top(){
	return top->data;
}



int main()
{



return 0;
}