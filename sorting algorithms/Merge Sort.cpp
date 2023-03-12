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
#define print_time() cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC  << " mS\n";


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

void merge(vector<int> &arr, int start, int mid, int end){
	vector<int> ans(end-start+1);

	int index1 = start, index2 = mid+1, index = 0;

	while(index1 <= mid && index2 <= end){
		if(arr[index1] <= arr[index2]){
			ans[index] = arr[index1];
			index1++; index++;
		}
		else{
			ans[index] = arr[index2];
			index2++; index++;
		}
	}

	while(index1 <= mid){
		ans[index] = arr[index1];
		index1++; index++; 
	}

	while(index2 <= end){
		ans[index] = arr[index2];
		index2++; index++;
	}

	for(int i=0,j=start;i<ans.size();i++,j++){
		arr[j] = ans[i];
	}

}

void merge_sort(vector<int> &arr, int start, int end){
	
	if(start >= end) return;

	int mid = start + (end-start)/2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid+1, end);
	merge(arr, start, mid, end);
}

int main()
{ 	

	vector<int> arr = {6,3,9,5,2,8};
	printArray();
	merge_sort(arr, 0, arr.size()-1);
	printArray();

return 0;
}