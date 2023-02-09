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
void printArray(vector<int> &arr){
	for(int i: arr){
		cout << i << space;
	}
	cout << nline;
}

// Function implementing Binary search (Note: Binary Search only works on sorted array)
int BinarySearch(vector<int> &arr, int num){
    int length = arr.size();
    int left = 0;
    int right = length-1;
    int mid;
    while(left <= right){
        mid = left + (right - left) /2;
        if(arr[mid] == num){
            return mid;
        }
        else if(arr[mid] > num){
            right = mid-1;
        }
        else if(arr[mid] < num){
            left = mid+1;
        }
    }
    return -1;
}


int BinarySearchRecursive(vector<int> &arr, int num, int left, int right){
    
    if(left > right) return -1;
    int mid = left + (right - left)/2;
    if(arr[mid] == num){
        return mid;
    }
    else if(arr[mid] > num){
        return BinarySearchRecursive(arr, num, n, left, mid-1);
    }    
    return BinarySearchRecursive(arr, num, n, mid+1, right);
    
}

int main()
{ 	
	
	vector<int> arr = {9, 12, 13, 15, 22, 56, 79, 83, 85}; // example array

	int index = BinarySearch(arr, 83); // testing the function

	cout << index << nline; // printing the index
	
return 0;
}