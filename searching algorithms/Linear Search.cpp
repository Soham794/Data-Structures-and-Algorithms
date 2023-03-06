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

// function to print the array
void printArray(vector<int> &arr, int n){
	for(int i: arr){
		cout << i << space;
	}
	cout << nline;
}

// Function implementing linear search
int LinearSearch(vector<int> &arr, int num){
	int length = arr.size(); // get the length of array to traverse
	int index = 0; // setting the starting index to 0 (as array indexing starts from 0)
	for(index = 0;index < length;index++){ // loop over the array and compare each element to target element
		if(arr[index] == num){ // if the element at that index matches with the target element
			return index;  	   // return that index
		} 
	}
	return -1; // if not found any matching element, return -1
}


int main()
{ 	
	
	vector<int> arr = {9,2,45,69,33}; // example array

	int index = LinearSearch(arr, 45); // testing the function

	cout << index << nline; // printing the index
	
return 0;
}