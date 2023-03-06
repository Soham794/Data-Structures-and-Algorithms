/*Soham Belokar*/
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define space " "
#define PB push_back
#define MP make_pair
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

// Function to print the array
void printArray(vector<int> &arr){
	for(int i: arr){
		cout << i << space;
	}
	cout << nline;
}

// BubbleSort sorting function
void bubbleSort(vector<int> &arr){
	int n = arr.size(); // get the length of the array
	for(int i=0;i<n;i++){ // loop over all the elements in the array
		for(int j=0;j<n-i-1;j++){ // loop from intial index to the remaining index
			if(arr[j] > arr[j+1]){ // if any element is greater than its next element 
				swap(arr[j], arr[j+1]); // swap values to make the array sorted
			}
		}
	}
}	

// BubbleSort implemented as recursive function
void bubbleSortRecursive(vector<int> &arr, int n){
	if(n==1){return;} // if size of array is 1

	for(int i=0;i<n-1;i++){ // loop over the all elements 
		if(arr[i] > arr[i+1]){swap(arr[i], arr[i+1]);} // and check if any greater element is present before smaller elements
	}												   // if so swap both elements

	bubbleSortRecursive(arr, n-1); // call the function for n-1 length
}

int main()
{ 	

fastio();

	vector<int> arr = {9,2,45,69,33}; // example array
	
	printArray(arr); // printing the original array
	bubbleSort(arr); // calling the sort function
	printArray(arr); // printing the sorted array
	// bubbleSortRecursive(arr, 5);
	// printArray(arr);
	
return 0;
}