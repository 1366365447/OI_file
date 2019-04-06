#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>

using std::vector;
const int MAX_N = 1000 + 10;

int n, k;
double val[MAX_N], cost[MAX_N], Y[MAX_N];

inline double judge(double x) {
	memset(Y, 0, sizeof(Y));
	
	for (int i = 1; i <= n; i++) {
		Y[i] = val[i] - x * cost[i];
	}
	
	std::sort(Y + 1, Y + n + 1, std::greater<double>());

	double ret = 0.0;
	for (int i = 1; i <= n - k; i++) {
		ret += Y[i];
	}
	
	return ret;
}	

int main() {
	
	while (~scanf("%d%d", &n, &k)) {
		if (n == 0 && k == 0) break;

		for (int i = 1; i <= n; i++) {
			scanf("%lf", &val[i]);
		}
		
		for (int i = 1; i <= n; i++) {
			scanf("%lf", &cost[i]);
		}
		
		double l = 0.0, r = 1.0, mid = 0.0;
		
		while (r - l >= 0.0001) {
			mid = (l + r) / 2.0;
			
			if (judge(mid) > 0.0) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		
		printf("%d\n", (int)(100 * l + 0.5));
	}
	
	
	return 0;
}