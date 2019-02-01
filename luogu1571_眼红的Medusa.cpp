#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

const int MAX_N = (int)(1e5 + 10);

int n, m;
int A[MAX_N], B[MAX_N];

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
	
	std::sort(B + 1, B + m + 1);
	
	for (int i = 1; i <= n; i++) {
		int l = 1, r = m, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			
			if (B[mid] <= A[i]) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		
		if (B[ans] == A[i]) printf("%d ", A[i]);
	}
	puts("");
	
	return 0;
}
