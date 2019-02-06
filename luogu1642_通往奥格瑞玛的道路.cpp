#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>

const int MAX_N = 10000 + 10;
const int MAX_E = 50000 + 10;
const int INF = 0x3f3f3f3f;

int n, m, b;
int f[MAX_N];

struct Edge {
    int next, to, val;

    Edge() { }
    Edge(int _next, int _to, int _val): next(next), to(_to), val(_val) { }
} edge[MAX_E << 1];
int head[MAX_N], cnt;

inline void Add(int u, int v, int w) {
    edge[++cnt].val = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int dis[MAX_N];
bool vis[MAX_N];
inline bool SPFA(int x) {
    std::queue<int> Que;
    
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));

    dis[1] = 0;
    Que.push(1);
    while (!Que.empty()) {
        int u = Que.front(); Que.pop();
        
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].val;
            if (f[v] > x) continue;

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = true;
                    Que.push(v);
                }
            }
        }

        vis[u] = false;
    }

    if (dis[n] > b) return false; // can't arrive
    return true; 
}

inline bool judge(int x) {
    if (f[1] > x) return false; // can't arrive
    
    return SPFA(x);
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &b);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);

        Add(u, v, w); Add(v, u, w);
    }

    int _f[MAX_N]; memcpy(_f, f, sizeof(f));
    std::sort(_f + 1, _f + n + 1);

    if (!SPFA(INF)) {
        puts("AFK");
        return 0;
    }
    
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        
        if (judge(_f[mid])) ans = _f[mid], r = mid - 1;
        else l = mid + 1;
    }

    printf("%d\n", ans);
	
    return 0;
}

