#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <set>

using std::multiset;
using std::stack;
const int MAX_N = 1352 + 10;

int n;

multiset<int> Edge[300];
stack<int> S;

int degree[MAX_N];

void Dfs(int x) {
	
	for (multiset<int>::iterator i = Edge[x].begin(); i != Edge[x].end(); i = Edge[x].begin()) {
		int v = *i;
		
		Edge[x].erase(i);
		Edge[v].erase(Edge[v].find(x));
		
		Dfs(v);
	}
	
	S.push(x);
}

int main() {
	
	scanf("%d", &n);
	
	int Min = 0x3f3f3f3f;
	
	for (int i = 1; i <= n; i++) {
		char u, v; std::cin >> u >> v;
		
		Edge[(int)u].insert((int)v);
		Edge[(int)v].insert((int)u);
		
		degree[(int)u]++, degree[(int)v]++;
		
		Min = std::min(Min, (int)u);
		Min = std::min(Min, (int)v);
	}
	
	int s = -1, e = -1;
	for (int i = 1; i <= 300; i++) {
		if (degree[i] % 2 == 1) {
			
			if (s == -1) s = i;
			else if (e == -1) e = i;
			else {
				puts("No Solution");
				return 0;
			}
		}
	}
	
	if (s == -1) Dfs(Min);
	else Dfs(s);
	
	while (!S.empty()) {
		printf("%c", (char)S.top());
		S.pop();
	}
	
	return 0;
}
