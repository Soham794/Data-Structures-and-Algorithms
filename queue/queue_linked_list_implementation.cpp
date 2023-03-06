/*Soham Belokar*/
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define space " "

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

struct Node{
	int data;
	Node* next;
};


Node *front = NULL, *rear = NULL;

bool isempty(){
	return (front==NULL && rear==NULL);
}

void enqueue(int val){

	if(isempty()){
		Node* temp = new Node;
		temp -> data = val;
		temp -> next = NULL;
		front = temp;
		rear = front;
	}
	else if(!isempty()){
		Node* temp = new Node;
		temp -> data = val;
		temp -> next = NULL;
		rear -> next = temp;
		rear = temp;
		
	}
}

void dequeue(){
	if(isempty()){
		cout << "Queue is empty" << nline;
		return;
	}
	else if(!isempty()){
		front = front -> next;
	}
}

int peekfront(){
	if(isempty()){ 
		cout << "Queue is empty" << nline;
		return -1;
	}
	return front -> data;
}


int peekrear(){
	if(isempty()){
		cout << "Queue is empty" << nline;
		return -1;
	}
	return rear -> data;
}

void printqueue(){
	if(isempty()){
		cout << "Queue is empty" << nline;
		return;
	}
	Node* temp = front;
	while(temp != NULL){
		cout << temp -> data << space;
		temp = temp -> next;		
	}
	cout << nline;
}

int main()
{ 

	enqueue(6); enqueue(7); enqueue(8); enqueue(9);
	printqueue();
	dequeue();
	printqueue();
	

return 0;
}