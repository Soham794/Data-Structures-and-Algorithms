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

// SentinelSearch Function
int SentinelSearch(vector<int> &arr, int num){
	
	int length = arr.size(); // get the length of array
	int last = arr[length - 1]; // store the last element in a variable

	arr[length - 1] = num; // replace the last element with the target element 
	
	int index=0; // initialize a variable to 0 to check indices of the array
	
	while(arr[index] != num){ // loop until not found
		index++;			 // if not found increment the index value and repeat
	}			// loop will terminate after finding target element at last index
	
	arr[length - 1] = last; // put the last element again at the last element 

	if((i<length-1) || (arr[length - 1] == num)){ // so, now if the index is less than the last index or
		return i;					// element at last index is equal to the target element return the index
	}
	return -1; // otherwise -1, as the element doesn't exist in the array
}


int main()
{ 	

fastio();

	vector<int> arr = { 10, 20, 180, 30, 60, 50, 110, 100, 70 }; // example array

	int index = SentinelSearch(arr, 110); // calling the sentinel search function

	cout << index << nline; // printing the index

	
return 0;
}