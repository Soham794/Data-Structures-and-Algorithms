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


// // fibonacci numbers using dynamic programming
// // memoization
int fib(int n, vector<int> &dp){
	if(n == 0) return 0;
	if(n == 1) return 1;

	if(dp[n] != -1) return dp[n];

	return dp[n] = fib(n-1,dp) + fib(n-2,dp);

}


int main()
{
fastio();
	
	int n;
	cin >> n;
	vector<int> dp(n+1, -1);

	cout << fib(n, dp) << nline;

	vector<int> tab(n+1, -1);
	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	cout << dp[n] << nline;
	
return 0;
}