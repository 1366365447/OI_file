#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

typedef long long LL;

using std::priority_queue;
using std::vector;
const int MAX_N = 10000 + 10;
const int MAX_E = 50000 + 10;

int n, m, t;
LL num[MAX_N];

struct Edge {
	int next, to;
	LL val;
} edge[MAX_E << 1];
int head[MAX_N], cnt;

inline void Add(int u, int v, LL w) {
	edge[++cnt].to = v;
	edge[cnt].val = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

struct Node {
	int v;
	LL val;
	
	Node(int _v, int _val): v(_v), val(_val) { }
	
	bool operator <(const Node& Other) const {
		return val > Other.val;
	}
};

LL dis[MAX_N];
int pre[MAX_N];
bool vis[MAX_N];
inline void Dijkstra(int s = 1) {
	
	for (int i = 1; i <= n; i++) dis[i] = LONG_MAX;	
	dis[s] = 0;
	
	priority_queue<Node, vector<Node> > Que;
	Que.push(Node(s, 0));
	
	while (!Que.empty()) {
		
		int x = Que.top().v; Que.pop();
		
		vis[x] = true;
		
		for (int i = head[x]; ~i; i = edge[i].next) {
			int v = edge[i].to; LL w = edge[i].val;
			if (vis[v]) continue;
		
			if (dis[x] + w == dis[v]) {
				if (x < pre[v]) {
					pre[v] = x;
					Que.push(Node(v, dis[v]));
					continue;
				}
			}
			
			if (dis[x] + w < dis[v]) {
				dis[v] = dis[x] + w;
				pre[v] = x;
				
				if (!vis[v]) {
					Que.push(Node(v, dis[v]));
				}
			}
		}
		
	}
	
}

LL node[MAX_N];

int main() {
	
	scanf("%d%d%d", &n, &m, &t);
	
	memset(head, -1, sizeof(head));
	memset(pre, -1, sizeof(pre));
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &num[i]);
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
		
		Add(u, v, w), Add(v, u, w);
	}
	
	Dijkstra();
	
	for (int i = 1; i <= n; i++) {
		
		int x = i;
		while (x != -1) {
			node[x] += num[i];
			x = pre[x];
		}
		
	}
	
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, (dis[i] - t) * (LL)node[i]);
	}
	printf("%lld\n", ans);
	
	return 0;
}