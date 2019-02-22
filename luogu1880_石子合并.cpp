#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

const int MAX_N = 200 + 10;

int n;
int num[MAX_N], pre[MAX_N];
int dp_max[MAX_N][MAX_N], dp_min[MAX_N][MAX_N];

int main() {
	
	memset(dp_min, 0x3f, sizeof(dp_min));
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		
		num[i + n] = num[i];
	}
	
	for (int i = 1; i <= 2 * n; i++) {
		pre[i] = pre[i - 1] + num[i];
		dp_max[i][i] = dp_min[i][i] = 0;
	}
	
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= 2 * n - 1; i++) { 
			int j = len + i - 1;
			
			for (int k = i; k <= 2 * n - 1 && k < j; k++) {
				dp_max[i][j] = std::max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + pre[j] - pre[i - 1]);
				dp_min[i][j] = std::min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + pre[j] - pre[i - 1]);
			}
		}
	}
	
	int Min = 0x3f3f3f3f, Max = 0;
	for (int i = 1; i <= n; i++) {
		int j = i + n - 1;
		
		Max = std::max(Max, dp_max[i][j]);
		Min = std::min(Min, dp_min[i][j]);
	}
	
	printf("%d\n%d\n", Min, Max);
	
	return 0;
}