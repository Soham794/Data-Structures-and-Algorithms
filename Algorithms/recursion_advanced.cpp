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


void printSubS(int ind, int n, vector<int> &arr, vector<int> &ans){
	if(ind >= n){
		for(int i: ans){
			cout << i << " ";
		}
		cout << nline;
		return;
	}

	ans.push_back(arr[ind]);
	printSubS(ind+1,n,arr,ans);
	ans.pop_back();
	printSubS(ind+1,n,arr,ans);

}

void subsequence(int ind, vector<int> &arr, int n, vector<int> &ans){
	if(ind >= n){
		cout << "{";
		for(int i: ans) cout << i << " ";
		cout << "}";
		cout << nline ;
		return;
	}

	ans.push_back(arr[ind]);
	subsequence(ind+1, arr,n, ans);
	ans.pop_back();
	subsequence(ind+1, arr, n, ans);

}


void PrintSubseqOfSum(int ind, vector<int> &arr, int sum, int s, int n, vector<int> &ans){
	if(ind >= n){
		if(sum == s){
			for(int i: ans){
				cout << i << " ";
			}
			cout << nline;
		}

		return;
	}

	ans.push_back(arr[ind]);
	s+=arr[ind];
	PrintSubseqOfSum(ind+1, arr, sum, s, n, ans);

	ans.pop_back();
	s-=arr[ind];
	PrintSubseqOfSum(ind+1, arr, sum, s, n, ans);
}


bool printS(int ind, int sum, int s, int n, vector<int> &arr, vector<int> &ans){
	if(ind >= n){
		if(sum == s){
			for(int i: ans){
				cout << i << " ";
			}
			cout << nline;
			return true;
		}
		return false;
	}
	ans.push_back(arr[ind]);
	s+=arr[ind];

	if(printS(ind+1, sum, s, n, arr, ans) == true){
		return true;
	}

	ans.pop_back();
	s-=arr[ind];

	if(printS(ind+1, sum, s, n, arr, ans) == true){
		return true;
	}

	return false;
}

int printCount(int ind, vector<int> &arr, int sum, int s, int n, vector<int> &ans){
	if(ind >= n){
		if(sum == s){
			return 1;
		}
		return 0;
	}

	ans.push_back(arr[ind]);
	s+=arr[ind];
	int sub1 = printCount(ind+1, arr, sum, s, n, ans);

	ans.pop_back();
	s-=arr[ind];
	int sub2 = printCount(ind+1, arr, sum, s, n, ans);

	return sub1 + sub2;
}

void printsubarr(vector<int> &arr, vector<int> &sub, int start, int end){

	if(end == arr.size()){
		return;
	}
	if(start > end){
		printsubarr(arr, sub, 0, end+1);
	}

	else{
		for(int i=start; i< end;i++){
			cout << arr[i] << " ";
		}
		cout << arr[end] << " ";
		cout << nline;
		printsubarr(arr,sub,start+1,end);
	}
	
}

void printSubArrSum(vector<int> &arr, vector<int> &sub, int start, int end){
	
	if(end == arr.size()){
		return;
	}

	cout << "SUM : " << accumulate(sub.begin(), sub.end(), 0);
	cout << nline;
	if(start >= end){
		sub.push_back(arr[end]);
		printSubArrSum(arr, sub, start, end+1);
	}
	else{
		sub.push_back(arr[end]);
		sub.erase(sub.begin());
		printSubArrSum(arr,sub, start+1,end);

	}



}

int gcd(int a ,int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}


int main()
{
fastio();
	
	vector<int> arr = {1,2,3,4};
	vector<int> ans;
	// printSubS(0,4,arr,ans);
	printsubarr(arr, ans, 0, 0);


return 0;
}	