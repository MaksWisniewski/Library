#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000 * 1000 + 7;

long long power(long long a, long long b, long long m = MOD) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
long long multiply(long long a, long long b, long long m = MOD) {
	long long ans = 0;
	while(b) {
		if(b&1)
			ans = ans + a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans % m;
}

long long divide(long long a, long long b) {
	return a * power(b, MOD - 2) % MOD;
}

int main() {
	cout << multiply(2, 3);
}
