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


// TernarySearch function
int TernarySearch(vector<int> &arr, int num){
	int n = arr.size();
	int left = 0, right = n-1;
	int mid1, mid2;
	
	while(left <= right){
		mid1 = left + (right - left)/3;
		mid2 = right - (right - left)/3;
		if(arr[mid1] == num){
			return mid1;
		}
		if(arr[mid2] == num){
			return mid2;
		}

		if(num < arr[mid1]){
			right = mid1-1;
		}
		else if(num > arr[mid2]){
			left = mid2+1;
		}
		else{
			left = mid1+1;
			right = mid2-1;
		}
	}

	return -1;

}


// TernarySearch implemented as a recursive function
int TernarySearchRecursive(vector<int> &arr, int left, int right, int num){
	
	if(left <= right){	
		int mid1 = left + (right - left)/3;
		int mid2 = right - (right-left)/3;
		
		if(arr[mid1] == num){
			return mid1;
		}
		if(arr[mid2] == num){
			return mid2;
		}
		if(num < arr[mid1]){
			return TernarySearchRecursive(arr, left, mid1-1, num);
		}
		else if(num > arr[mid2]){
			return TernarySearchRecursive(arr, mid2+1, right, num);
		}
		else{
			return TernarySearchRecursive(arr, mid1+1, mid2-1, num);
		}
	}

	return -1;

}

int main()
{ 	

fastio();

	vector<int> arr = {64, 25, 12, 22, 11}; // example array
	
	printArray(arr); // printing the original array


return 0;
}