#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>

const int MAX_N = 100 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int G[MAX_N][MAX_N], dis[MAX_N][MAX_N], pre[MAX_N][MAX_N];
int path[MAX_N];

int loop, cnt;

int main() {
	
	while (~scanf("%d%d", &n, &m)) {
		memset(path, 0, sizeof(path));
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				G[i][j] = INF;
			}
			G[i][i] = 0;
		}
	
		for (int i = 1; i <= m; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			
			if (w < G[u][v]) {
				G[u][v] = G[v][u] = w;
			}
		}
		
		memcpy(dis, G, sizeof(G));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				pre[i][j] = j;
			}
		}
		
		loop = INF;
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j || j == k || i == k) continue;
					if (dis[i][j] == INF || G[i][k] == INF || G[k][j] == INF) continue;
					
					if (dis[i][j] + G[i][k] + G[k][j] < loop) {
						loop = dis[i][j] + G[i][k] + G[k][j];
						
						cnt = 0; int t = i;
						while (t != j) {
							path[++cnt] = t;
							t = pre[t][j];
						}
						path[++cnt] = j, path[++cnt] = k;
						
					}
				}
			}
			
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dis[i][k] == INF || dis[k][j] == INF) continue;
					
					if (dis[i][k] + dis[k][j] < dis[i][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
						pre[i][j] = pre[i][k];
					}
				}
			}
		}
		
		if (loop == INF) {
			puts("No solution.");
			return 0;
		}
		
		for (int i = 1; i <= cnt; i++) {
			if (i != cnt) printf("%d ", path[i]);
			else printf("%d\n", path[i]);
		}
	
	}
	
	
	return 0;
}