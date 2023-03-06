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
void printArray(vector<int> &arr){
	for(int i: arr){
		cout << i << space;
	}
	cout << nline;
}

// Function implementing Binary search (Note: Binary Search only works on sorted array)
int BinarySearch(vector<int> &arr, int num){
    int length = arr.size();    // first get the length of the array
    int left = 0;               // set the left boundary of search space to 0
    int right = length-1;       // set the right boundary of search space to length-1(as the last index is length-1)
    int mid;                    // declaring a variable to store the value of mid index
    while(left <= right){       // repeat the process of searching until the boundary is not emptied or left boundary is les than equal to right boundary
        mid = left + (right - left) /2;    // calculate the value of the middle index of the boundary
        if(arr[mid] == num){               // if the element at middle index is equal to target element
            return mid;                    // return that index
        }
        else if(arr[mid] > num){           // if the element is less than the middle index element
            right = mid-1;                 // move the rightmost boundary to left side i.e. to mid-1 as the elements 
        }                                  // on the right side are greater than target element and we can avoid searching them
        
        else if(arr[mid] < num){           // if the element is greater than the middle index element
            left = mid+1;                  // move the leftmost boundary to right side i.e. to mid+1 as elements
        }                                  // on the left side are lesser than target element and we can aviod searching them
    }

    return -1;  // if element not found and the boundary emptied the element is not present in the array, so we return -1
}


int BinarySearchRecursive(vector<int> &arr, int num, int left, int right){
    
    if(left > right) return -1; // if the boundary is emptied or leftmost boundary became more than rightmost boundary return -1 as element doesn't exist in the given boundary
    int mid = left + (right - left)/2; // get the value of middle index of the current search space
    if(arr[mid] == num){ // if the element at middle index is equal to the target element
        return mid;      // return that index
    }
    else if(arr[mid] > num){ // if the element at middle index is greater than the target element that means we have to search in between leftmost boundary and mid-1
        return BinarySearchRecursive(arr, num, n, left, mid-1); // so reduce the size of rightmost boundary to mid-1 and return the function call
    }    
    return BinarySearchRecursive(arr, num, n, mid+1, right); // if the element at middle index is smaller than the target element that means we have to search in between 
        // rightmost boundary and mid+1, so change the leftmost boundary to mid+1 and return the function call
    
}

int main()
{ 	
	
	vector<int> arr = {9, 12, 13, 15, 22, 56, 79, 83, 85}; // example array

	int index = BinarySearch(arr, 83); // testing the function

	cout << index << nline; // printing the index
	
return 0;
}