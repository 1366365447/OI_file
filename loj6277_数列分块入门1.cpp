#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using std::min;
const int MAX_N = 50000 + 10;

int n;
int L[MAX_N], R[MAX_N];
int A[MAX_N], belong[MAX_N], tag[MAX_N];

inline void Add(int l, int r, int v) {
	if (belong[l] == belong[r]) {
		for (int i = l; i <= r; i++) {
			A[i] += v;
		}
		return;
	}
	
	for (int i = l; i <= R[belong[l]]; i++) {
		A[i] += v;
	}
	for (int i = L[belong[r]]; i <= r; i++) {
		A[i] += v;
	}
	for (int i = belong[l] + 1; i <= belong[r] - 1; i++) {
		tag[i] += v;
	}
}

int main() {
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	
	int block = (int)sqrt(n), num = 0;
	
	if (n % block == 0) 
		num = n / block;
	else 
		num = n / block + 1;
	
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * block + 1;
		R[i] = i * block;
	}
	R[num] = n;
	
	for (int i = 1; i <= n; i++) {
		belong[i] = (i - 1) / block + 1;
	}
	
	for (int i = 1; i <= n; i++) {
		int opt, l, r, c; scanf("%d%d%d%d", &opt, &l, &r, &c);
		
		if (opt == 0) {
			Add(l, r, c);
		}
		else if (opt == 1) {
			printf("%d\n", A[r] + tag[belong[r]]);
		}
	}
	
	return 0;
}
