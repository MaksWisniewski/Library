#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll, ll> P;

const int SIZE = 1 << 18;
const int LOG = 18;

int timer = 0, root = 1;
int jump[SIZE][LOG+2], pre[SIZE], post[SIZE];
vector<int> G[SIZE];

int n;

void dfs(int v, int father) {
	pre[v] = ++timer;
	jump[v][0] = father;

	for(int x : G[v]) {
		if(x != father)
			dfs(x, v);
	}
	post[v] = ++timer;
}

bool is_ancestor(int u, int v) {
	return pre[u] <= pre[v] and post[u] >= post[v];
}

inline void prepare() {
	dfs(1, -1);
	
	jump[root][0] = root;
	for(int k = 1; k <= LOG; k++) {
        for(int i = 1; i <= n; i++){
             jump[i][k] = jump[ jump[i][k-1] ][k-1];
        }
    }
}

int lca(int u, int v) {
	if(is_ancestor(u, v))	return u;
	if(is_ancestor(v, u))	return v;

	for(int i = LOG; i >= 0; --i)
		if(!is_ancestor(jump[u][i], v))
			u = jump[u][i];

	return jump[u][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);


	cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		G[a].push_back(b);	
		G[b].push_back(a);
	}

	prepare();

	cout << lca(1, 5) << " " << lca(4, 3) << " " << lca(4, 2);	
}