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

// function to print the array
void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << space;
	}
	cout << nline;
}

// Function implementing linear search
int LinearSearch(int arr[], int num){
	int length = sizeof(arr)/sizeof(arr[0]); // get the length of array to traverse
	int index = 0; // setting the starting index to 0
	for(index = 0;index < length;index++){
		if(arr[index] == num){ // if the element at that index matches with the requirement
			return index;  	   // return that index
		} 
	}
	return -1; // if not found any matching element, return -1
}


int main()
{ 	
	
	int arr[5] = {9,2,45,69,33}; // example array

	int index = LinearSearch(arr, 45); // testing the function

	cout << index << nline; // printing the index
	
return 0;
}