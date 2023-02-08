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

void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << space;
	}
	cout << nline;
}


int LinearSearch(int arr[], int num){
	int length = sizeof(arr)/sizeof(arr[0]);
	int curr = 0;
	for(curr = 0;curr < length;curr++){
		if(arr[curr] == num) return curr;
	}
	return -1;
}


int main()
{ 	
	
	int arr[5] = {9,2,45,69,33};

	int index = LinearSearch(arr, 45);

	cout << index << nline;
	
return 0;
}