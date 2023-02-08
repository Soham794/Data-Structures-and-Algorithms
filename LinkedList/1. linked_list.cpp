#include <bits/stdc++.h>

using namespace std;

#define nline "\n"
#define space " "

typedef long long int ll;

struct Node{
	int data;
	Node* next;
};


Node* insertAtBegining(Node* head, int val){

	Node* temp = new Node;
	temp->data = val;
	temp->next = NULL; 
	if(head != NULL ) { temp->next = head; }

	head=temp;
	return head;
}

Node* insertAtTail(Node* head,int val){

	Node* temp = new Node;
	temp->data = val;
	temp->next = NULL;
	if(head==NULL){
		head=temp;
		return head;
	}

	Node* last = getLastElement(head);
	last->next=temp;

	return head;
}

Node* insertAtNth(Node* head,int pos ,int val){

	if(pos==0){return head;}
	Node* temp;
	Node* temp1=head;

	Node* newnode = new Node;
	newnode->data=val;
	newnode->next=NULL;
	
	if(pos == 1){
		newnode->next=head;
		head=newnode;
		return head;
	}

	for(int i=1;i<pos-1;i++){
		temp1=temp1->next;
	}
	temp=temp1->next;

	temp1->next=newnode;
	newnode->next=temp;


	return head;

}

Node* deleteAtNth(Node* head, int pos){

	if(pos==0){return head;}
	Node* temp=head;
	if(pos==1){
		head=temp->next;
		free(temp);
		return head;
	}

	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}

	Node* temp1=temp->next;
	temp->next= temp1->next;

	// free(temp1);
	delete temp1;

	return head;

}

Node* getLastElement(Node* head){


	while(head->next != NULL){
		head=head->next;
	}

	return head;

}

Node* reverseList(Node* head){

	Node *prev = NULL , *curr = head, *thenext;

	while(thenext != NULL){
		thenext=curr->next;
		curr->next=prev;
		prev=curr;
		curr=thenext;
	}

	head = prev;

	return head;

}

Node* reverseListRecursive(Node* head, Node* prev=NULL){

	if(head == NULL){
		head = prev;
		return head;
	}

	Node * curr = head, * thenext = curr->next;

	curr->next=prev;


	return reverseListRecursive(thenext, curr);
}

// // incomplete
// Node* temphead;
// Node* reverseListRecursive2(Node* temp){

// 	if(temp->next == NULL){
// 		temphead=temp;
// 		return temp;
// 	}
// 	Node* curr;
// 	curr=reverseListRecursive2(temp->next);

// 	curr->next=temp;
// 	temp->next=NULL;

// 	return temphead;


// }

void printList(Node* head){
	
	while(head!=NULL){
		cout << head->data << space;
		head=head->next;
	}
	cout << nline;
}

void printRecursive(Node* head){

	if(head==NULL){cout << nline; return;}
	cout << head->data << space;

	printRecursive(head->next);
}

void printInReverseRecursive(Node* head){

	if(head == NULL){ cout << nline; return; }

	printInReverseRecursive(head->next);
	cout << head->data << space;
	

}

int main()
{

	//creating head of the linked list
	Node* head=NULL;// initially pointing to NULL

	// //creating the first node
	// Node* temp = new Node;
	// temp->data = 1;
	// temp->next = NULL;

	// //storing the address of the first/new node in head
	// head=temp;
	// cout << head->data;
	
	// // can also be done using function created
	// insertAtBegining(head,1);
	// cout << head->data;

	// inserting n elements
	int n; cin >> n;

	// for(int i=1;i<=n;i++){
	// 	head=insertAtBegining(head,i);
	// }

	// //printing the list
	// Node* temp = head;// creating an temp variable to iterate over elements
	// while(temp!=NULL){
	// 	cout << temp->data;
	// 	temp=temp->next;
	// }
	
	// // can also be done using function created 
	// printList(head);


	for(int i=1;i<=n;i++){ head=insertAtTail(head,i);}
	// printList(head);

	// //inserting at Nth position using function created
	// head=insertAtNth(head,1,0);
	// printList(head);

	// //deleting the Nth node
	// head=deleteAtNth(head,2);
	// printList(head);
	
	// head=reverseList(head);
	// printList(head);

	// head=reverseListRecursive(head);
	// printList(head);

	// printInReverseRecursive(head);

	// head=reverseListRecursive2(head);

	printRecursive(head);



return 0;
}