#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>

const int MAX_N = 10000 + 10;
const int MAX_E = 100000 + 10;

struct Edge {
	int next, to;
} edge[MAX_E << 1];
int head[MAX_N], cnt;

struct Node {
	int x, fa;

	Node() {}
	Node(int _x, int _fa): x(_x), fa(_fa) {}
};

int n, m;
int color[MAX_N];

inline void Add(int u, int v) {
	edge[++cnt].to = v, edge[cnt].next = head[u], head[u] = cnt;
	edge[++cnt].to = u, edge[cnt].next = head[v], head[v] = cnt;
}

bool vis[MAX_N], error;

int black = 0, white = 0;
inline void Bfs(int x) {
	std::queue<Node> Que;

	Que.push(Node(x, x));
	color[x] = 1;
	vis[x] = true;

	while (!Que.empty()) {
		if (error) break;

		int u = Que.front().x, fa = Que.front().fa;
		Que.pop();

		for (int i = head[u]; ~i; i = edge[i].next) {
			int v = edge[i].to;
			if (v == fa) continue;

			if (vis[v] && color[v] != color[u] ^ 1) {
				error = true;
				break;
			}

			color[v] = color[u] ^ 1;
			if (color[v] == 1) ++black;
			else ++white;
			
			vis[v] = true;
			Que.push(Node(v, u));
		}
	}
}

bool appear[MAX_N];
int main() {
	memset(head, -1, sizeof(head));
	memset(color, -1, sizeof(color));
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		
		Add(u, v);
		appear[u] = appear[v] = true;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (error) break;
		if (!appear[i]) continue;
		if (!vis[i]) {
			
			white = 0, black = 1;
			Bfs(i);
			
			ans += std::min(white, black);
		}
	}
	
	if (error) { puts("Impossible"); return 0; }
	
	printf("%d\n", ans);
	
	return 0;
}
