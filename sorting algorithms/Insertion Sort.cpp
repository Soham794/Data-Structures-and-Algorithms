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

// appropriate for datasets which are partially sorted
// InsertionSort sorting function
void InsertionSort(vector<int> &arr){
	int length = arr.size(); // get the length of the array to be sorted
	int key, j; // declare two variables,
	// 1. to store the current element of the traversing array,
	// 2. to store and check all previous indices of that element
	for(int i=1;i<length;i++){ 
		key = arr[i]; // store the current element of the array
		j = i-1; // store the index of preceeding element to the current element
		while(j>=0 && arr[j] > key){ // until the index is greater than 0 and every element at these indexes is greater than
			arr[j+1] = arr[j]; 		//  the stored element, we replace the next element at that index with the element at jTH index
			j-=1; // also decrement j, to check all previous elements until 0
		}
		arr[j+1] = key; // once got to the right index where element preceeding are smaller and elements infront of that are greater
			// store the key element at that index
	}
}


// InsertionSort implemented recursively
void InsertionSortRecursive(vector<int> &arr, int n=1){
	if(n == arr.size()) return; 
	int key = arr[n];
	int j = n-1;
	while(j>=0 && arr[j]>key){
		arr[j+1] = arr[j];
		j-=1;
	}
	arr[j+1] = key;
	InsertionSortRecursive(arr, n+1);
}

int main()
{ 	

fastio();

	vector<int> arr = {64, 25, 12, 22, 11}; // example array
	
	printArray(arr); // printing the original array
	InsertionSort(arr); // calling the sort function
	// InsertionSortRecursive(arr); // calling the recursive sort function
	printArray(arr); // printing the sorted array

return 0;
}