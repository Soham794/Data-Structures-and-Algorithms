#include <bits/stdc++.h>

using namespace std;

#define nline "\n"
#define space " "

typedef long long int ll;

// stacks (LIFO) applications
//    -function calls/recursion
// 	  -undo operations in any text editor 
// 	  -compiler checks whether the brackets in the code are balanced or not using stack
//	  -reversing things ex- linked list, strings.
//    -infix , prefix, and postfix operations
const int N=1e3+10;
int A[N];
int top = -1;

void push(int val){
	if(top == N-1){cout << "stackoverflow" << nline; return;}
	top++;
	A[top]=val;
	//A[++top] = val; // //also works 
}

void pop(){
	if(top == -1){cout << "No element to pop" << nline; return;}
	top--;
}

void print(){
	cout << "stack: ";
	for(int i=0;i<=top;i++){
		cout << A[i] << space;
	}
	cout << nline;
}

void peek(){
	cout << A[top] << space;
}

bool isEmpty(){
	if(top==-1){
		return true;
	}
	return false;
}

int main()
{

	for(int i=1;i<=5;i++){
		push(i);
	}
	
	print();
	for(int i=1;i<=5;i++){
		print();
		pop();
	}
	
	(isEmpty()) ? cout << "TRUE" << nline : cout << "FALSE" << nline;



return 0;
}