#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>

int n, k;

int Min = 0x3f3f3f3f;

int main() {
	
	scanf("%d%d", &n, &k);
	
	for (int i = 1; i <= k; i++) {
		for (int j = 30; j >= 0; j--) {
			if (n >= (1 << j)) {
				Min = std::min(Min, j);
				n -= (1 << j);
				break;
			}
		}
	}
	
	if (n != 0) printf("%d\n", (1 << Min) - n);
	else puts("0");
	
	return 0;
}
