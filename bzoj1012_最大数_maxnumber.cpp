#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long LL;
const int MAX_N = 200000 + 10;

int M;
LL D, t = 0;

struct Node {
	int l, r;
	LL value;
} tree[MAX_N << 2];

void build(int p, int l, int r) {
	tree[p].l = l, tree[p].r = r;
	if (l == r) {
		return;
	}
	
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1|1, mid + 1, r);
}

void update (int p, int x, LL v) {
	if (tree[p].l == tree[p].r) {
		tree[p].value = v;
		return;
	} 
	
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (x <= mid) update(p << 1, x, v);
	else update(p << 1|1, x, v);
	
	tree[p].value = std::max(tree[p << 1].value, tree[p << 1|1].value);
}

LL query(int p, int l, int r) {
	if (l <= tree[p].l && r >= tree[p].r) {
		return tree[p].value;
	}
	
	LL ret = 0;
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (l <= mid) ret = std::max(ret, query(p << 1, l, r));
	if (r > mid) ret = std::max(ret, query(p << 1|1, l, r)); 
	
	return ret;
}

int main() {
	
	scanf("%d%lld", &M, &D);
	
	int L = 0;
	build(1, 1, M);
	
	while (M--) {
		char opt[5]; LL x;
		scanf("%s%lld", opt, &x);
	
		if (opt[0] == 'A') {
			x = (x + t) % D;
			update(1, ++L, x);
		}
		else if (opt[0] == 'Q') {
			t = query(1, L - (int)x + 1, L);
			printf("%lld\n", t);
		}
	}

	return 0;
}
