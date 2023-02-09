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

// SelectionSort sorting function
void SelectionSort(vector<int> &arr){
	int length = arr.size(); // get the length of arr
	int min_index; // declare a variable to store the index of minimum element
	for(int i=0;i<length-1;i++){ // loop till length-1
		min_index = i; // intially, let the minimum index be i
		for(int j=i+1;j<length;j++){ // loop from i+1 till end of the array
			if(arr[j] < arr[min_index]){ // if the element at the current index in the loop is smaller than element at minium index
				min_index = j; // update min index as the index of that element
			}
		} // this loop gets the value of index of smallest element from i+1 index
		if(min_index != i){ // as previously initialized, if the we found another index which has the smallest element
			swap(arr[i], arr[min_index]); // then swap those element to store the minimum element at its correct place
		}
	}
}


// SelectionSort implemented as a recursive function
void SelectionSortRecursive(vector<int> &arr, int index = 0){
	
	if(index == arr.size()) return; // if the size of index from which we need to search the minimum element
				// becomes equals to size of the array, sorting is completed and we return 

	int min_index = index; // let the current index be the index of minimum element
	for(int i=index+1;i<arr.size();i++){ // loop from that index+1 till end of the array
		if(arr[j] < arr[min_index]){ // if any smaller element than the element at min_index is found
			min_index = i; 			// then we store the value of that index in min_index
		}
		if(min_index != index){ // and swap it with the element if their index value is different
			swap(arr[i], arr[min_index]);
		}
	}

	SelectionSortRecursive(arr, index+1); // decrease the window size of searching the minimum element by 
		// increasing the value of index

}

int main()
{ 	

fastio();

	vector<int> arr = {64, 25, 12, 22, 11}; // example array
	
	printArray(arr); // printing the original array
	SelectionSort(arr); // calling the sort function
	printArray(arr); // printing the sorted array

	// selectionSortRecursive(arr, arr.size());
	// printArray(arr);
	
return 0;
}