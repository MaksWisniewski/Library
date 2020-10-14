#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int DSIZE = 1 << 20;
ll t[2*DSIZE], lazy[2*DSIZE];
bool czy[2*DSIZE];

void propagate(int node, int rozmiar) {
	t[node] = lazy[node] * rozmiar;
	if(node < DSIZE) {
		lazy[2*node] = lazy[2*node + 1] = lazy[node];
		czy[2*node] = czy[2*node + 1] = true;
	}
	czy[node] = 0;
}

void update(int val, int l, int r, int node = 1, int L = 0, R = SIZE - 1) {
	if(czy[node])
		propagate(node, R - L + 1);	

	if(r < L or R < l) return;
	if(l <= L and R <= r) {
		lazy[node] = val;
		propagate(node, R - L + 1);
		return;
	}
	int M = (L+R) / 2;
	update(val, l, r, 2*node, L, M);
	update(val, l, r, 2*node+1. M+1, R);
	
	t[node] = t[2*node] + t[2*node+1];
}

ll query(int l, int r, int node = 1, int L = 0, R = SIZE - 1) {
	if(czy[node])
		propagate(node, R - L + 1);

	if(r < L or R < l) return 0;
	
	if(l <= L and R <= r) {
		return t[node];
	}

	return query(val, l, r, 2*node, L, M) + query(val, l, r, 2*node+1. M+1, R);
}

inline void build() {
	for(int i = DSIZE - 1; i > 0; i--) {
		t[i] = t[2*i] + t[2*i + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cint.tie(0);		cout.tie(0);

	int n;	cin >> n;
	for(int i = 1; i <=n; i++)
		cin >> t[i+DSIZE];

	build();

	int q;	cin >> q;
	



}