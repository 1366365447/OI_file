#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

const int MAX_N = 1000 + 10;
const double INF = 0x7f7f7f7f;
const double eps = 1e-8;

int n;
double X[MAX_N], Y[MAX_N], Z[MAX_N];

double Max;
double cost[MAX_N][MAX_N], len[MAX_N][MAX_N], newlen[MAX_N][MAX_N];

inline double Dis(double x1, double x2, double y1, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double dis[MAX_N];
bool vis[MAX_N];
inline double Prim(int s) {
	
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
		dis[i] = newlen[s][i];
	}
	
	dis[s] = 0.0;
	vis[s] = true;
	
	double ans = 0;
	for (int j = 1; j < n; j++) {
		double min = INF;
		int v = 0;
		
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && min > dis[i]) {
				min = dis[i];
				v = i;	
			}
		}
		
		if (min == INF) break;
		vis[v] = true;
		ans += min;
		
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dis[i] = std::min(dis[i], newlen[v][i]);
			}
		}
	}
	
	return ans;
}

inline bool judge(double x) {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			newlen[j][i] = newlen[i][j] = cost[i][j] - x * len[i][j];
		}
	}
	
	if (Prim(1) >= 0) return true;
	return false;
}

int main() {
	
	while (~scanf("%d", &n) && n) {
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf%lf", &X[i], &Y[i], &Z[i]);	
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cost[i][j] = cost[j][i] = fabs(Z[i] - Z[j]);
				len[i][j] = len[j][i] = Dis(X[i], X[j], Y[i], Y[j]);
				Max = std::max(Max, cost[i][j] / len[i][j]);
			}
		}
		
		double l = 0.0, r = 50;
		while (r - l >= eps) {
			double mid = (l + r) / 2.0;
			
			if (judge(mid)) l = mid;
			else r = mid;
		}
		
		printf("%.3f\n", l);
	}
	
	return 0;
}
