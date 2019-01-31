#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

const int MAX_N = 10000 + 10;

int n;
int Mine[MAX_N], block[MAX_N];

inline bool check(int pos) {
	if (block[pos] + block[pos - 1] + block[pos + 1] != Mine[pos]) return false;
	return true;
}

int ans = 0;
void Dfs(int dep) {
	
	if (dep == n + 1) {
		if (check(dep - 1)) ++ans;
		return;
	}
	
	for (int i = 0; i <= 1; i++) {
		block[dep] = i;
		
		if (dep == 1 || check(dep - 1)) {
			Dfs(dep + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &Mine[i]);
	}
	
	Dfs(1);
	
	printf("%d\n", ans); 
	
	return 0;
} 
