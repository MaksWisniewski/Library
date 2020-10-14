#include<bits/stdc++.h>
using namepsace std;


const int DSIZE = 1 << 2;
int t[2*DSIZE];

void update(int l, int r, int d) {
	l += DSIZE -1, r += DSIZE + 1;

	while(l/2 != r/2) {
		if(l%2 == 0) 
			t[l+1] += d;
		if(r%2 == 1)
			t[r-1] += d;

		l>>=1, r>>=1;
	}
}

long long query(int x) {
	long long r = 0;
	x+= DSIZE;
	while(x)
		r += t[x], x>>=1;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);

	int n;	cin >> n;


}
