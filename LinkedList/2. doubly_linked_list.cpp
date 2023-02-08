#include <bits/stdc++.h>

using namespace std;

#define nline "\n"
#define space " "

typedef long long int ll;

struct Node{

	int data;
	Node* prev;
	Node* next;
};

Node* head=NULL;

Node* getLastNode(){
	if(head==NULL){return head;}
	Node* last=head;
	while(last->next!=NULL){last=last->next;}

	return last;

}
void insertAtBegining(int val){
	
	Node* temp = new Node;
	temp->prev=NULL;
	temp->data=val;
	temp->next=NULL;
	if(head == NULL){
	head=temp;
	return;
	}
	
	temp->next=head;
	head->prev=temp;

	head=temp;

}

void insertAtTail(int val){

	Node* newnode = new Node;
	newnode->prev=NULL;
	newnode->data=val;
	newnode->next=NULL;

	if(head == NULL){head = newnode; return;}

	Node* last=getLastNode();
	last->next=newnode;
	newnode->prev=last;


}

void printList(){

	Node* temp=head;
	while(temp!=NULL){
		cout << temp->data << space;
		temp=temp->next;
	}
	cout << nline;
}

void printListRecursive(Node* temp=head){

	if(temp == NULL){cout << nline; return;}
	cout << temp->data << space ;
	printListRecursive(temp->next);

}

Node* getNth(int pos){

	Node* temp=head;
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}

	return temp;
}

void insertAtNth(int pos , int val){

	Node* newnode = new Node;
	newnode->data=val;
	newnode->next=NULL; 
	newnode->prev=NULL;

	Node* temp = getNth(pos);
	Node* thenext = temp->next;

	newnode->next=thenext;
	thenext->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;

}

void deleteAtNth(int pos){

	Node* temp;
	Node* temp1;
	Node* curr = getNth(pos);
	temp = curr->next;
	temp=temp->next;

	temp1=curr->next;
	free(temp1);

	curr->next = temp;
	temp->prev = curr;


}

// // incomplete

// void reverseList(){

// 	Node *curr=head, *prev=head->prev , *thenext;

// 	while(thenext!=NULL){
// 		thenext=curr->next;

// 	}

// }

int main()
{

	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		insertAtTail(i);
		
	}

	printList();
	
	insertAtNth(2,0);
	printListRecursive();

	deleteAtNth(2);

	printListRecursive();



return 0;
}