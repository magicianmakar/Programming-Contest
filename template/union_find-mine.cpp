#include <bits/stdc++.h>

using namespace std;

#define mx 222222

int n , m;
vector< int > con[mx];
int sz[mx] , root[mx];

int union_find(int r){
	return root[r] == r ? root[r] : root[r] = union_find(root[r]);
}

int connect(int u , int v){
	u = union_find(u) , v = union_find(v);
	if(u == v) return 0;
	if(sz[u] < sz[v]) swap(u , v);
	root[v] = u , sz[u] += sz[v] , sz[v] = 0;
}

int main(){
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++ ){
		int u , v;
		cin>>u>>v;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	for(int i = 0 ; i < n ; i++ ) sz[i] = 1 , root[i] = i;
}
