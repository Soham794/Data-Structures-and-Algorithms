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
#define _test_cases int _TEST; cin >> _TEST; while(_TEST--)

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;


struct Node{
	Node* links[26];
	bool flag = false;
	bool contains(char ch){
		return (links[ch-'a']!=NULL);
	}
	Node* get(char ch){
		Node* node;
		links[ch-'a'] = node;
		return links[ch-'a'];
	}
	Node* next(char ch){
		return links[ch-'a'];
	}
	void setEnd(){ flag = true;}
	bool isEnd(){return flag;}
};


class Trie{
	Node* root;	
	public:	
	Trie(){root = new Node();}
	void insert(string word);
	bool search(string word);
	bool prefix(string pref);
};
	
void Trie::insert(string word){
	Node* node = root;
	for(int i=0;i<word.size();i++){
		if(!node->contains(word[i])){
			node = node->get(word[i]);
		}
		node = node->next(word[i]);
	}
	node->setEnd();
}


bool Trie::search(string word){
	Node* node = root;
	for(int i=0;i<word.size();i++){
		if(!node->contains(word[i])) return false;
		node = node->next(word[i]);
	}
	return node->isEnd();
}

bool Trie::prefix(string pref){
	Node* node = root;
	for(int i=0;i<pref.size();i++){
		if(!node->contains(pref[i])) return false;
		node = node->next(pref[i]);
	}
	return true;
}

int main(){

return 0;
}