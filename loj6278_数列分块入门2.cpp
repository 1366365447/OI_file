#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>

using std::vector;
const int MAX_N = 50000 + 10;

int n;
int L[MAX_N], R[MAX_N];
int A[MAX_N], belong[MAX_N], tag[MAX_N];

vector<int> V[MAX_N];

inline void resort(int group) {
	
	V[group].clear();
	for (int i = L[group]; i <= R[group]; i++) {
		V[group].push_back(A[i]);
	}
	
	std::sort(V[group].begin(), V[group].end());
}

inline void Add(int l, int r, int v) {
	
	if (belong[l] == belong[r]) {
		for (int i = l; i <= r; i++) {
			A[i] += v;
		}
		
		resort(belong[l]);
		return;
	}
	
	for (int i = l; i <= R[belong[l]]; i++) {
		A[i] += v;
	}
	for (int i = L[belong[r]]; i <= r; i++) {
		A[i] += v;
	}
	
	resort(belong[l]), resort(belong[r]);
	
	for (int i = belong[l] + 1; i <= belong[r] - 1; i++) {
		tag[i] += v;
	}
}

inline int query(int l, int r, int v) {
	
	int ret = 0;
	
	if (belong[l] == belong[r]) {
		for (int i = l; i <= r; i++) {
			if (A[i] + tag[belong[l]] < v)
				++ret;
		}
		
		return ret;
	}
	
	for (int i = l; i <= R[belong[l]]; i++) {
		if (A[i] + tag[belong[l]] < v)
			++ret;
	}
	
	for (int i = L[belong[r]]; i <= r; i++) {
		if (A[i] + tag[belong[r]] < v)
			++ret;
	}
	
	for (int i = belong[l] + 1; i <= belong[r] - 1; i++) {
		int _v = v - tag[i];
		ret += std::lower_bound(V[i].begin(), V[i].end(), _v) - V[i].begin();
	}
	
	return ret;
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
		V[belong[i]].push_back(A[i]);
	}
	
	for (int i = 1; i <= belong[n]; i++) {
		std::sort(V[i].begin(), V[i].end());
	}
	
	for (int i = 1; i <= n; i++) {
		int opt, l, r, c; scanf("%d%d%d%d", &opt, &l, &r, &c);
		
		if (opt == 0) {
			Add(l, r, c);
		}
		else if (opt == 1) {
			printf("%d\n", query(l, r, c * c));
		}
	}
	
	return 0;
}
