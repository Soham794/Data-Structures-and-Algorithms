/*Soham Belokar*/
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define space " "

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

// // strongly connected components
// --------------------------------------------------------------------------------------------------
void dfsRecursive(int src, vector<int> &vis, vector<vector<int>> &adj ){

	vis[src] = 1;
	cout << src << space;
	for(auto i: adj[src]){
		if(!vis[i]){
			dfsRecursive(i, vis, adj);
		}
	}

}


void dfsIterative(int src, int n, vector<vector<int>> &adj){

	vector<int> vis(n+1,0);
	stack<int> st;
	st.push(src);

	while(!st.empty()){
		int num = st.top();
		
		cout << num << space;
		vis[num] = 1;
		st.pop();

		for(int i=0; i<adj[num].size(); i++){

			if(!vis[(adj[num][i])]){
				st.push(adj[num][i]);
				vis[adj[num][i]] = 1;
			}
		}
	}

}


void bfs(int src, vector<int> &vis, vector<vector<int>> &adj){

	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int num = q.front();
			
		cout << num << space ;
		vis[num] = 1;
	
		q.pop();

		for(int i=0;i<adj[num].size();i++){
			if(!vis[adj[num][i]]){
				vis[adj[num][i]] = 1;
				q.push(adj[num][i]);
			}
		}
	}

}

// // disconnected components
// ----------------------------------------------------------------------------------
bool cycleBFS(vector<vector<int>> &adj, vector<int> &vis, int src){
	
	queue<pair<int,int>> q;
	vis[src] = 1;
	q.push({src, -1});

	while(!q.empty()){
		int node = q.front().first;
		int prev = q.front().second;
		q.pop();
		for(int i: adj[node]){
			if(!vis[i]){
				vis[i] = 1;
				q.push({i,node});
			}
			else if(prev != i){
				return true;
			}
		}


	}
	return false;

}

bool checkcycleBFS(vector<vector<int>> &adj, int nodes){
	vector<int> vis(nodes+1, 0);
	for(int i=1;i<=nodes;i++){
		if(!vis[i]){
			if(cycleBFS(adj, vis, i)){
				return true;
			}
		}
	}
	return false;
}

bool cycleDFS(vector<vector<int>> &adj, vector<int> &vis, int src, int prev = -1){
	vis[src] = 1;
	for(int i: adj[src]){
		if(!vis[i]){
			vis[i] = 1;
			if(cycleDFS(adj, vis, i, src)){
				return true;
			}
		}
		else if(prev != i){
			return true;
		}
	}
	return false;
}

bool checkcycleDFS(vector<vector<int>> &adj, int nodes){
	vector<int> vis(nodes+1, 0);
	for(int i=1;i<=nodes;i++){
		if(!vis[i]){
			if(cycleDFS(adj, vis, i)){
				return true;
			}
		}
	}
	return false;
}


bool BipartiteBFS(vector<vector<int>> &adj, vector<int> &color, int src){
	color[src] = 1;
	queue<int> q;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i: adj[node]){
			if(color[i] == -1){
				color[i] = 1-color[node];
				q.push(i);
			}
			else if(color[i] == color[node]){
				return false;
			}
		}
	}
	return true;
}

bool checkBipartite(vector<vector<int>> &adj, int nodes){
	vector<int> color(nodes+1, -1);
	for(int i=1;i<=nodes;i++){
		if(color[i] == -1){
			if(!BipartiteBFS(adj, color, i)){
				return false;
			}
		}
	}
	return true;
}

bool BipartiteDFS(vector<vector<int>> &adj, vector<int> &color, int src){
	if(color[src] == -1) color[src] = 1;
	for(int i: adj[src]){
		if(color[i] == -1){
			color[i] = 1-color[src];
			if(!BipartiteDFS(adj, color, i)){
				return false;
			}
		}
		else if(color[i] == color[src]){
			return false;
		}
	}
	return true;
}

bool checkBipartiteDFS(vector<vector<int>> adj, int nodes){
	vector<int> color(nodes+1, -1);
	for(int i=1;i<=nodes;i++){
		if(color[i] == -1){
			if(!BipartiteDFS(adj, color, i)){
				return false;
			}
		}
	}
	return true;
}
// // Directed Graphs

bool DirectedDFScycle(vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfsvis, int src){
	vis[src] = 1;
	dfsvis[src] = 1;
	for(int i: adj[src]){
		if(!vis[i]){
			if(DirectedDFScycle(adj, vis, dfsvis, i)){
				return true;
			}
		}
		else if(dfsvis[i]){
			return true;
		}
	}
	dfsvis[src] = 0;
	return false;
}

bool checkCycleDirectedDFS(vector<vector<int>> &adj, int nodes){
	vector<int> vis(nodes+1, 0), dfsvis(nodes+1, 0);
	for(int i=1;i<=nodes;i++){
		if(!vis[i]){
			if(DirectedDFScycle(adj, vis, dfsvis, i)){
				return true;
			}
		}
	}
	return false;
}

// kahns algorithm
bool checkCycleDirectedBFS(vector<vector<int>> &adj, int nodes){
	vector<int> indegree(nodes+1,0);
	queue<int> q;
	
	for(int i=0;i<nodes;i++){
		for(int j: adj[i]){
			indegree[j]++;
		}
	}

	for(int i=0;i<nodes;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	int ct = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ct++;
		for(int i: adj[node]){
			indegree[i]--;
			if(indegree[i] == 0){
				q.push(i);
			}
		}

	}

	if(ct == nodes){return false;}
	return true;

}

void findtoposort(vector<vector<int>> &adj, vector<int> &vis, stack<int> &st, int src){
	vis[src] = 1;
	for(int i: adj[src]){
		if(!vis[i]){
			findtoposort(adj, vis, st, i);
		}
	}
	st.push(src);
}

vector<int> toposort(vector<vector<int>> &adj, int nodes){
	vector<int> vis(nodes+1,0);
	stack<int> st;
	for(int i=0;i<nodes;i++){
		if(!vis[i]){
			findtoposort(adj, vis, st, i);
		}
	}
	vector<int> topo;
	while(!st.empty()){
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
}
	

vector<int> toposortBFS(vector<vector<int>> &adj, int nodes){
	vector<int> indegree(nodes+1, 0);
	queue<int> q;
	for(int i=0;i<nodes;i++){
		for(int j: adj[i]){
			indegree[j]++;
		}
	}

	for(int i=0;i<nodes;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	vector<int> topo;

	while(!q.empty()){
		int node = q.front();
		topo.push_back(node);
		q.pop();
		for(int i: adj[node]){
			indegree[i]--;
			if(indegree[i] == 0){
				q.push(i);
			}
		}

	}
	return topo;

}

void shortestDistance(vector<vector<int>> &adj, int n, int src){
	
	vector<int> distance(n,INT_MAX);
	queue<int> q;

	q.push(src);
	distance[src] = 0;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int i: adj[curr]){
			int dis = distance[curr] + 1;
			if(dis < distance[i]){
				distance[i] = dis;
				q.push(i);
			}
		}
	}


	for(int i: distance){
		cout << i << " ";
	}
}

void toposortWDAG_DFS(vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int> &st, int src){
	vis[src] = 1;
	for(auto i: adj[src]){
		if(!vis[i.first]){
			toposortWDAG_DFS(adj, vis, st, i.first);
		}
	}
	st.push(src);
}

vector<int> toposortWDAG(vector<vector<pair<int,int>>> &adj, int nodes){
	vector<int> vis(nodes+1,0);
	stack<int> st;
	
	vector<int> ans;

	for(int i=0;i<nodes;i++){
		if(!vis[i]){
			toposortWDAG_DFS(adj, vis, st, i);
		}
	}

	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	return ans;

}


void shortestDistanceWDAG(vector<vector<pair<int,int>>> &adj, int src){
	int n = adj.size();
	vector<int> distance(n,INT_MAX);
	vector<int> topo = toposortWDAG(adj, n);

	distance[*topo.begin()] = 0;

	for(int i: topo){
		if(distance[i] != INT_MAX){
			for(auto it: adj[i]){
				int dis = distance[i] + it.second;
				if(dis < distance[it.first]){
					distance[it.first] = dis;
				}
			}
		}
	}

	cout << nline;
	for(int i: distance){
		cout << i << " ";
	}
	cout << nline;

}


vector<int> dijkstrasShortestPathAlgo(vector<vector<pair<int,int>>> &adj, int src){
	vector<int> distance(adj.size(),INT_MAX);
	distance[src] = 0;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

	q.push({src,0});

	while(!q.empty()){
		int node = q.top().first;
		int dis = q.top().second;
		q.pop();

		for(auto i: adj[node]){
			int new_dis = dis + i.second;
			if(new_dis < distance[i.first]){
				distance[i.first] = new_dis;
				q.push({i.first,new_dis});
			}
		}

	}

	return distance;

}

void MST_prims1(vector<vector<pair<int,int>>> &adj, int start){

	// brute force approach 
	// O(N^2)
	int n = adj.size();
	vector<int> parent(n+1, -1);
	vector<int> key(n+1, INT_MAX);
	vector<bool> node_in_mst(n+1, false);

	key[start] = 0;

	for(int i=0;i<n;i++){
		
		int curr_node, curr_dis = INT_MAX;

		for(int j=0;j<n;j++){
			if(node_in_mst[j] == false && key[j] < curr_dis){
				curr_node = j;
				curr_dis = key[j];
			}
		}

		node_in_mst[curr_node] = true;

		for(auto j : adj[curr_node]){
			int node = j.first;
			int dis = j.second;
			if(node_in_mst[node] == false && dis < key[node]){
				parent[node] = curr_node;
				key[node] = dis;
			}
		}

	}

	for(int i=1;i<n;i++){	
		cout << parent[i] << "->" << i << nline;
	}
	cout << nline;

}

void MST_prims2(vector<vector<pair<int,int>>> &adj, int start){
	// priority queue approach
	// O()

	int n = adj.size();
	vector<int> parent(n+1,-1);
	vector<int> key(n+1,INT_MAX);
	vector<bool> node_in_mst(n+1,false);

	key[start] = 0;
// 12678250  7239100
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	// {node, distance}
	pq.push({start, 0});
	int ans = 0;
	for(int i=0;i<n;i++){
		int curr_node = pq.top().first;
		int dis = pq.top().second;
		pq.pop();
		if(node_in_mst[curr_node]) continue;
		node_in_mst[curr_node] = true;
		ans += dis;
		for(auto j : adj[curr_node]){
			int node = j.first;
			int dis = j.second;
			if(node_in_mst[node] == false && dis < key[node]){
				key[node] = dis;
				parent[node] = curr_node;
				pq.push({node,dis});
			}
		}

	}

	cout << ans % MOD << nline;

	for(int i=1;i<n;i++){
		// x is the parent of y
		cout << parent[i] << "->" << i << nline;
	}cout << nline << nline;

}


int main()
{ 	
	// adjacency list implementation of undirected graph
	
	// // undirected graph input

	// int n,e;
	// cin >> n >> e;
	// vector<vector<int>> adj(n+1);
	// for(int i=0;i<e;i++){
	// 	int u,v;
	// 	cin >> u >> v;
	// 	adj[u].push_back(v);
	// 	adj[v].push_back(u);
	// }

	// for(int i=0;i<=n;i++){
	// 	cout << i << "->" << space;
	// 	for(int j=0;j<adj[i].size();j++){
	// 		cout << adj[i][j] << space;
	// 	}
	// 	cout << nline;
	// }
	
	// vector<int> vis(n+1,0);
	// dfsRecursive(1 ,vis ,adj);
	// cout << nline;
	// dfsIterative(1, n, adj);
	
	// cout << nline ;
		
	// bfs(1, vis, adj);
	
	// cout << nline;
	// cout << "Cycle Detection : " << nline;
	// (checkcycleBFS(adj, n)) ? cout << "TRUE" : cout << "FALSE";
	// cout << nline << nline;
	// (checkcycleDFS(adj, n)) ? cout << "TRUE" : cout << "FALSE";

	// cout << nline << nline;
	// cout << "Bipartite : " << nline;
	// (checkBipartite(adj, n)) ? cout << "YES Bipartite" : cout << "NOT Bipartite";
	// cout << nline << nline;
	// (checkBipartiteDFS(adj, n)) ? cout << "YES Bipartite" : cout << "NOT Bipartite";

	// cout << nline << nline;

	// // Directed graph input
	
	// int dn,de;
	// cin >> dn >> de;
	// vector<vector<int>> Dadj(dn+1);
	
	// for(int i=0;i<de;i++){
	// 	int u,v;
	// 	cin >> u >> v;
	// 	Dadj[u].push_back(v);
	// }
	
	// for(int i=0;i<=dn;i++){
	// 	cout << i << "->" << space;
	// 	for(int j=0;j<Dadj[i].size();j++){
	// 		cout << Dadj[i][j] << space;
	// 	}
	// 	cout << nline;
	// }

	// cout << nline << nline;

	// (checkCycleDirectedDFS(Dadj, dn)) ? cout << "True" : cout << "False";	
	// cout << nline;
	// (checkCycleDirectedBFS(Dadj, dn)) ? cout << "True" : cout << "False";	

	// cout << nline << nline;
	// vector<int> topologicalorder = toposort(Dadj, dn);
	// for(int i: topologicalorder){
	// 	cout << i << " ";
	// }	
	// cout << nline << nline;

	// vector<int> topoorder = toposortBFS(Dadj, dn);
	// for(int i: topoorder){
	// 	cout << i << " ";
	// }

	// cout << nline << nline;

	// shortestDistance(adj, n, 0);
	// int wn, we;
	// cin >> wn >> we;
	// vector<vector<pair<int,int>>> weightedDag(wn+1);

	// for(int i=0;i<we;i++){
	// 	int u,v,w;
	// 	cin >> u >> v >> w;
	// 	weightedDag[u].push_back({v,w});
	// }

	// for(int i=0;i<=wn;i++){
	// 	cout << i << "->" << space;
	// 	for(auto it: weightedDag[i]){
	// 		cout << "{" << it.first << "," << it.second << "}" << space;
	// 	}
	// 	cout << nline;
	// }

	// shortestDistanceWDAG(weightedDag, 0);

	int n,e;

	cin >> n >> e;

	vector<vector<pair<int,int>>> weightedUndirectedGraph(n+1);

	for(int i=0;i<e;i++){
		int u,v,w;
		cin >> u >> v >> w;

		weightedUndirectedGraph[u].push_back({v,w});
		weightedUndirectedGraph[v].push_back({u,w});
	}


	for(int i=0;i<=n;i++){
		cout << i << "->" << space;
		for(auto j : weightedUndirectedGraph[i]){
			cout << "{" << j.first << " " << j.second << "}";
		}
		cout << nline;
	}cout << nline << nline;

	// vector<int> shortest_path = dijkstrasShortestPathAlgo(weightedUndirectedGraph,1);
	// for(int i=0;i<=n;i++){
	// 	if(i == 0){continue;} // in this case;
	// 	cout << shortest_path[i] << " ";
	// }
	// cout << nline;

	// MST_prims1(weightedUndirectedGraph, 0);
	int start;
	cin >> start;
	cout << nline << nline;
	MST_prims2(weightedUndirectedGraph, start);

	return 0;
}