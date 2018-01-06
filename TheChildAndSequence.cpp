/*
n m
a
1 l r
2 l r x
3 k x

input
5 5
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3
1 1 3
output
8
5
*/

/** invalid solution **/

#include <iostream>

using namespace std;

int t[200005];
int d[200005];
int a[100005];
int n, h;
void init() {
	for(int i = 0; i < n; ++i) t[n + i] = a[i];
	
	for(int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
	
	int p = n * 2, cnt = 0;
	while(p > 1) p >>= 1, cnt++;
	
	h = cnt;
}

int query(int l, int r) {
	pushdown(l += n), pushdown((r += n) - 1);
	
	int sum = 0;
	for(; l < r; l >>= 1, r>>= 1) {
		if(l & 1) sum += t[l++];
		if(r & 1) sum += t[--r];
	}
	return sum;
}

void applyMod(int p, int v) {
	t[p] = tp % v;
	if(p < n) d[p] = v;
}

void pushup(int p) {
	while(p > 1) {
		p >>= 1;
		int l = t[p << 1];
		int r = t[p << 1 | 1];
		if(d[p] > 0) {
			l %= d[p], r %= d[p];
		}
		t[p] = l + r;
	}
}

void pushdown(int p) {
	for(int s = h; s > 0; --s) {
		int pp = p >> s;
		if(d[pp] > 0) {
			applyMod(pp << 1, d[pp]);
			applyMod(pp << 1 | 1, d[pp]);
			d[pp] = 0;
		}
	}
}

void modUpdate(int l, int r, int x) {
	int l0, r0;
	for(l += n, r+= n, l0 = l, r0 = r; l < r; l >>= 1, r >>= 1) {
		if(l & 1) pushdown(l), applyMod(l, x), l++;
		if(r & 1) --r, pushdown(r), applyMod(r, x);
	}
	pushup(l0);
	pushup(r0 - 1);
}

void setUpdate(int k, x) {
	pushdown(k += n);
	t[k] = x;
	pushup(k);
}

int main() {
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	
	init();
	
	for(int i = 0; i < m; ++i) {
		int type;
		scanf("%d", &type);
		
		if(type == 1) {
			int l, r;
			scanf("%d %d", &l, & r);
			printf("%d\n", query(l, r));
		}
		else if(type == 2) {
			int l, r, x;
			scanf("%d %d %d", &l, &r,&x);
			modUpdate(l, r, x);
		}
		else if(type == 3) {
			int k, x;
			scanf("%d %d", &k, &x);
			setUpdate(k, x);
		}
	}
	
	return 0;
}

