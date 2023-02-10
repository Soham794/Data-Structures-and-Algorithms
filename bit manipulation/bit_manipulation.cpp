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



// getbit function returns whether the bit is 1 at the given position
bool getbit(int n, int pos){
	if ((n & (1<<pos)) != 0){return true;}
	else return false;
}

// setbit function sets the bit at given position (setting a bit means setting it to 1)
int setbit(int n, int pos){
	return (n | (1<<pos));
}

// clearbit function clears the bit at given position (clearing means setting it to 0)
int clearbit(int n, int pos){
	int mask=~(1<<pos);
	return (n & (mask));
}

// updatebit function updates the value of bit (0 or 1) at given position
int updatebit(int n, int pos,int val){
	int mask = ~(1<<pos);
	n = n & mask;
	return (n | (val<<pos));
}

// numberofone function returns the number of 1's in the binary representation of the given number
int numberofone(int n){
	int ans=0;
	while(n!=0){
		if(n & 1 != 0) ans++;
		n=n>>1;
	}

	return ans;
}


// subsets function generates all possible subsets of an array using bit manipulation
void subsets(vector<int> &arr, int n){

	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				cout << arr[j] << space;
			}

		}
		cout << nline;
	}
}

// unique function returns the unique element in the array of duplicate elements
int unique(vector<int> &arr, int n){

	int xorsum=0;
	for(int i=0;i<n;i++){
		xorsum=xorsum^arr[i];
		cout << xorsum << nline;
	}

	return xorsum;
}


// numberofbits function returns the number of total bits used in the formation of the given number
int numberofbits(int x){
	int ans=0;
	while(x!=0){
		x=x>>1;
		ans++;
	}
	return ans;
}

int main()
{

return 0;
}

