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

const int N = 1e5;
// parent array to store the parents of group
// a vertex is a parent of itself if it is not in any group or is an individual vertex
// other wise the nodes in some group has a common parent
int parent[N];

void make(int v){
	parent[v] = v;
}

int find(int v){
	if(parent[v] == v) return v;
	return find(parent[v]);

}

void Union(int a, int b){
	int parent_b = parent[b];
	int parent_a = parent[a];
	parent[b] = parent[a];
}


int main()
{
fastio();
	
	

return 0;
}