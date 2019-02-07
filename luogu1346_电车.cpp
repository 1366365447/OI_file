#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>

const int MAX_N = 100 + 10;
const int INF = 0x3f3f3f3f;

int n, s, t;
bool vis[MAX_N];
int G[MAX_N][MAX_N], dis[MAX_N];

inline void SPFA() {
    std::queue<int> Que;
    
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));

    Que.push(s);
    dis[s] = 0;
    while (!Que.empty()) {
        int x = Que.front(); Que.pop();
        
        for (int i = 1; i <= n; i++) {
            if (G[x][i] == INF) continue;

            if (dis[x] + G[x][i] < dis[i]) {
                dis[i] = dis[x] + G[x][i];
                
                if (!vis[i]) {
                    Que.push(i);
                    vis[i] = true;
                }
            }
        }

        vis[x] = false;
    }

}

int main() {

    scanf("%d%d%d", &n, &s, &t);
    
    memset(G, 0x3f, sizeof(G));
    for (int i = 1; i <= n; i++) {
        G[i][i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        int k; scanf("%d", &k);

        for (int j = 1; j <= k; j++) {
            int v; scanf("%d", &v);

            if (j == 1) G[i][v] = 0;
            else G[i][v] = 1;
        }
    }
    
    SPFA();

    if (dis[t] == INF) puts("-1");
    else printf("%d\n", dis[t]);

    return 0;
}
