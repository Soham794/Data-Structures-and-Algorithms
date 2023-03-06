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

int BinarySearch(vector<int> &arr, int num, int left, int right){               
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


int ExponentialSearch(vector<int> &arr, int num){
	int n = arr.size();
	if(arr[0] == num){
		return 0;
	}

	int i=1;
	while(i < n && arr[i] <= num){
		i*=2;
	}
	return BinarySearch(arr, num, i/2, min(i, n-1));
}


int main()
{ 	

fastio();

	vector<int> arr = {64, 25, 12, 22, 11}; // example array
	
	printArray(arr); // printing the original array


return 0;
}