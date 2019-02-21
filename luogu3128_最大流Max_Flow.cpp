#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

const int MAX_N = 50000 + 10;

int n, k;

struct Edge {
	int next, to;
} edge[MAX_N << 1];
int head[MAX_N], cnt;

inline void Add(int u, int v) {
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int f[MAX_N][21], Dep[MAX_N], node[MAX_N];
void Dfs(int x, int fa) {
	Dep[x] = Dep[fa] + 1;
	
	for (int i = 1; i <= 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	
	for (int i = head[x]; ~i; i = edge[i].next) {
		int v = edge[i].to;
		if (v == fa) continue;
		
		f[v][0] = x;
		Dfs(v, x);
	}
}

inline int LCA(int x, int y) {
	if (Dep[x] < Dep[y]) std::swap(x, y);
	
	for (int i = 20; i >= 0; i--) {
		if (Dep[f[x][i]] >= Dep[y]) x = f[x][i];
		if (x == y) return x;
	}
	
	for (int i = 20; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	
	return f[x][0];
}

int ans = 0;
void Dfs2(int x) {
	
	for (int i = head[x]; ~i; i = edge[i].next) {
		int v = edge[i].to;
		if (v == f[x][0]) continue;
		
		Dfs2(v);
		node[x] += node[v];
	}
	
	ans = std::max(ans, node[x]);
}

int main() {
	
	memset(head, -1, sizeof(head));
	
	scanf("%d%d", &n, &k);
	
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		
		Add(u, v), Add(v, u);
	}
	
	Dfs(1, 0);
	
	for (int i = 1; i <= k; i++) {
		int u, v; scanf("%d%d", &u, &v);
		
		int lca = LCA(u, v);
		node[u] += 1, node[v] += 1, node[lca] -= 1, node[f[lca][0]] -= 1;
	}
	
	Dfs2(1);
	printf("%d\n", ans);
	
	return 0;
}