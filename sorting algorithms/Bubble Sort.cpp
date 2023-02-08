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


void bubbleSort(int arr[], int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}

}	


void bubbleSortRecursive(int arr[], int n){
	if(n==1){return;}

	for(int i=0;i<n-1;i++){
		if(arr[i] > arr[i+1]){swap(arr[i], arr[i+1]);}
	}

	bubbleSortRecursive(arr, n-1);
}

int main()
{ 	
	
	int arr[5] = {9,2,45,69,33};
	
	// printArray(arr, 5);
	// bubbleSort(arr,5);
	// bubbleSortRecursive(arr, 5);
	
	
return 0;
}