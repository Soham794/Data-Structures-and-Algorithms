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

const int N = 1e7 + 7;
int primes[N] = {0};

void generateprimes(){
	for(int i=2; i*i<=N; i++){
		if(primes[i] == 0){
		for(int j=i*i; j<=N; j+=i){
			primes[j] = 1;
			}
		}
	}
}

vector<ll> primefactors(ll x){
	vector<ll> ret;
	int index = 0;
	for(ll p: primes){
		if(index == 0){index++; continue;}
		if(p == 0){
			if(index*index > x){
				if(x>1){
					ret.push_back(x);
					x = 1;
				}
			}
			else{
				while(x%index == 0){
					ret.push_back(index);
					x/=index;
				}
			}
		}
		
		index++;
	}
	return ret;
}

int main()
{
fastio();
	
	int n;
	cin >> n;
	generateprimes();

	vector<ll> factors = primefactors(n);
	for(ll i: factors){
		cout << i << space;
	}
	
return 0;
}
