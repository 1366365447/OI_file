#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>

const int MAX_N = (int)(1e5 + 10);

int n, m;
int f[MAX_N * 4];

std::set<int> Ans;

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main () {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		f[i] = i;
		f[n + i] = n + i;
		f[2 * n + i] = 2 * n + i;
	}
	
	for (int i = 1; i <= m; i++) {
		char opt[5]; int x, y;
		scanf("%s%d%d", opt, &x, &y);
		
		if (opt[0] == 'E') {
			f[find(x)] = f[find(2 * n + y)];
			f[find(y)] = f[find(2 * n + x)];
		}
		else {
			f[find(x)] = f[find(y)];
			f[find(x)] = f[find(n + y)];
			f[find(n + x)] = f[find(y)];
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		Ans.insert(find(f[i]));
	}
	printf("%d\n", (int)Ans.size());
	
	return 0;
}
