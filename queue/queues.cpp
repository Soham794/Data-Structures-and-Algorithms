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

// // Queue (FIFO) applications:
//		- Spooling in printers
//		- CPU puts processes into a queue (Process scheduling)
//		- Simulating wait
//		- In operating systems (First Come First Serve)
//		- buffer for devices like keyboard
//  	- In graph algorithm BFS (Breadth First Search)

const int N = 1e5 + 5;
int arr[N];

int front = -1, rear = -1;

bool isempty(){return (front == -1 && rear == -1);}

void enqueue(int val){
	if(isempty()){
		front = 0; 
		rear = 0;
	}
	else if(!isempty()){
		if((rear + 1)%N == front){cout << "Queue is full" << nline; return;}
		rear = (rear+1)%N;

	}
	// // can be done if we have to set an endpoint to a queue
	// else if(!isempty()){
	// 	++rear;
	// }
	// else if(rear = N-1){cout << "Queue is full" << nline;}

	arr[rear] = val;
}

void dequeue(){
	if(isempty()){
		cout << "Queue is empty" << nline;
		return;
	}	
	else if(front == rear){front = -1; rear = -1; return;}
	else if(!isempty()){
		front = (front+1)%N;
	}	
}

int peekfront(){
	if(isempty()){return -1;}

	return arr[front];
}

int peekrear(){
	if(isempty()){return -1;}

	return arr[rear];
}

void printqueue(){
	for(int i=front; i<=rear; i++){
		cout << arr[i] << space;
	}
	cout << nline;
}

int main()
{ 

	enqueue(5); enqueue(7); enqueue(1);
	printqueue();
	dequeue();
	printqueue();
	enqueue(9); enqueue(3);
	printqueue();
	dequeue();
	printqueue();

return 0;
}