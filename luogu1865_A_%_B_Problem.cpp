#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using std::vector;
const int MAX_N = 1000000 + 10;

int n, m;

int cnt;
bool vis[MAX_N];
vector<int> Prime(1);
inline void GetPrime(int N = 1000000) {
	
	vis[0] = vis[1] = true;
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) {
			++cnt;
			Prime.push_back(i);
		}
		
		for (int j = 1; j <= cnt && i * Prime[j] <= N; j++) {
			vis[i * Prime[j]] = true;
			if (i % Prime[j] == 0) break;
		}
	}
}

int main() {
	
	GetPrime();
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		
		int l, r; scanf("%d%d", &l, &r);
		
		if (l < 1 || r > m) {
			puts("Crossing the line");
			continue;
		}
		
		int pos1 = std::lower_bound(Prime.begin(), Prime.end(), l) - Prime.begin();
		int pos2 = std::upper_bound(Prime.begin(), Prime.end(), r) - Prime.begin();
		
		printf("%d\n", pos2 - pos1);
	}
	
	return 0;
}