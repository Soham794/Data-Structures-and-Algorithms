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

struct Stack{
	int top;
	ll capacity;
	int* arr;
};

Stack* createstack( ll capacity){

	Stack* stack = new Stack();

	stack -> top = -1;
	stack -> capacity = capacity;
	stack -> arr = new int[(stack->capacity * sizeof(int))];

	return stack;
}

bool isempty(Stack* stack){

	return stack->top == -1;

}

int peek(Stack* stack){
	if(!isempty(stack)){return stack->arr[stack->top];}
	return -1;
}

int pop(Stack* stack){

	if(!isempty(stack)){ return stack->arr[--stack->top];}
	return '$';

}

void push(Stack* stack ,int val){
	stack -> arr [++stack->top] = val;
}

void printstack(Stack* stack){
	
	int i=0;

	while(true){
		cout << stack->arr[i] << space;
		if(stack->arr[stack->top] == stack->arr[i]){break;}
		i++;
	}

	cout << nline;

}

int main()
{ 

	Stack* st = createstack(100);
	push(st,1); push(st,4); push(st,3); push(st,5);

	// printstack(st);
	
	

return 0;
}