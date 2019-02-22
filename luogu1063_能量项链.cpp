#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>

const int MAX_N = 200 + 10;

int n;
int num[MAX_N], dp[MAX_N][MAX_N];

int main() {
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		
		num[i + n] = num[i];
	}
	
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= 2 * n - 1; i++) {
			int j = len + i - 1;
		
			for (int k = i; k < j && k <= 2 * n - 1; k++) {
				dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j] + num[i] * num[k + 1] * num[j + 1]);
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int j = i + n - 1;
		
		ans = std::max(ans, dp[i][j]);
	}
	printf("%d\n", ans);
	
	return 0;
}