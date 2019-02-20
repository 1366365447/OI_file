#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>

using std::set;
const int MAX_N = 100000 + 10;

int A, B, P;
int f[MAX_N];

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	
	if (fx != fy) {
		f[fx] = fy;
	}
}

int Prime[MAX_N], cnt;
bool vis[MAX_N];
inline void Eratosthenes() {
	
	vis[0] = vis[1] = true;
	for (int i = 2; i <= B; i++) {
		if (!vis[i]) {
			Prime[++cnt] = i;
			
			for (int j = 2 * i; j <= B; j += i) {
				vis[j] = true;
			
				if (i >= P && j >= A) {
					Union(i, j);
				}
			}
		}
	}
}

int main() {
	
	scanf("%d%d%d", &A, &B, &P);
	
	for (int i = 1; i <= 100000; i++) f[i] = i;
	
	Eratosthenes();
	
	set<int> s; s.clear();
	for (int i = A; i <= B; i++) {
		s.insert(find(f[i]));
	}
	
	printf("%d\n", s.size());
	
	return 0;
}