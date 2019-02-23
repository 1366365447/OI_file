#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>

using std::vector;
const int MAX_N = 100000 + 10;

int n;

vector<int> Edge[MAX_N];

int main() {
	
	scanf("%d", &n);
	
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}
	
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = std::max(Max, (int)Edge[i].size() + 1);
	}
	
	printf("%d\n", Max);
	
	return 0;
}