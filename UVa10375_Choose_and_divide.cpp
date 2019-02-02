#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>

const int MAX_N = 10000 + 10;

int p, q, r, s;

bool vis[MAX_N];
int Prime[MAX_N], tot;
inline void GetPrime(int n) {
	memset(vis, false, sizeof(vis));
	memset(Prime, 0, sizeof(Prime));
	tot = 0;
	
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) Prime[++tot] = i;	
		for (int j = 1; j <= tot && i * Prime[j] <= n; i++) {
			vis[i * Prime[j]] = true;
			if (i % Prime[j] == 0) break;
		}
	}	
}

int Pow[MAX_N];
inline void mult(int n, int k) {
	for (int i = 1; i <= tot; i++) {
		while (n % Prime[i] == 0) {
			n /= Prime[i];
			Pow[i] += k;
		}
		if (n == 1) break;
	}
}

inline void fac(int n, int k) {
	for (int i = 1; i <= n; i++) {
		mult(i, k);
	}
}

int main() {

	GetPrime(10000);
	
	while (~scanf("%d%d%d%d", &p, &q, &r, &s)) {
		memset(Pow, 0, sizeof(Pow)); 
		
		fac(p, 1), fac(s, 1), fac(r - s, 1);
		fac(q, -1), fac(p - q, -1), fac(r, -1);
		
		double ans = 1;
		for (int i = 1; i <= tot; i++) {
			ans *= std::pow((double)Prime[i], (double)Pow[i]);
		} 
		printf("%.5f\n", ans);
	}

	return 0;
}
