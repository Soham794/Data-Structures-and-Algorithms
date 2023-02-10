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


bool getbit(int n, int pos){
	if ((n & (1<<pos)) != 0){return true;}
	else{return false;}
}

int setbit(int n, int pos){

	return (n | (1<<pos));
}

int clearbit(int n, int pos){
	int mask=~(1<<pos);
	return (n & (mask));
}

int updatebit(int n, int pos,int val){
	int mask = ~(1<<pos);
	n = n & mask;

	return (n | (val<<pos));
}

int numberofone(int n){
	int ans=0;
	int temp=0;
	while(n!=0){
		if(n & (1<<temp) != 0){ans++;}
		temp++;
		n=n>>1;
	}

	return ans;
}

void subsets(int arr[], int n){

	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				cout << arr[j] << space;
			}

		}
		cout << nline;
	}
}

int unique(int arr[] ,int n){

	int xorsum=0;
	for(int i=0;i<n;i++){
		xorsum=xorsum^arr[i];
		cout << xorsum << nline;
	}

	return xorsum;
}


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

int n1=5,n2=2;

	// if(getbit(n1,n2)==true){cout << "TRUE";}
	// else{cout << "FALSE";}

	// n1=setbit(n1,1);
	// cout << n1;

	// n1=clearbit(n1,0);
	// cout << n1;

	// cout << updatebit(n1,1,1);

	// int n = 17;
	// if((n & (n-1)) != 0){cout << "NOT a power of 2";}
	// else{cout << "A power of 2";}
	
	// cout << numberofone(n);	

	// int arr[5] = {1,2,3,4,5};
	// subsets(arr , 5);
	// int a = numberofbits(5);
	// cout << a;

	if(getbit(5,0) == true){cout << "TURE" << nline;}
	else{ cout << "FALSE" << nline;}
	// int arr[]={1,2,3,9,3,2,6,1,6};
	// cout << unique(arr,9);
	

	

return 0;
}

