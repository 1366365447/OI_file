#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

const int MAX_N = 200 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int t[MAX_N], G[MAX_N][MAX_N];

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    memset(G, 0x3f, sizeof(G));
    for (int i = 0; i < n; i++) G[i][i] = 0;

    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);

        G[u][v] = G[v][u] = w;
    }

    int q; scanf("%d", &q);

    int k = 0;
    while (q--) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);

        while (t[k] <= z && k < n) { 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
                }
            }
            ++k;
        }

        if (G[x][y] == INF || t[x] > z || t[y] > z) puts("-1");
        else printf("%d\n", G[x][y]);
    }

    return 0;
}
