/*
n m k
s
1 l r c
2 l r d
input
3 1 2
112
2 2 3 1
1 1 3 8
2 1 2 1
output
NO
YES
*/
#include <iostream>

using namespace std;

struct T {
	int h, int l, int r, int d;
};

int n, m, k, h;
char s[100005];
T t[200005];
int pw[100005], sum_pw[100005];
int MD = 1e9 + 7, P = 4243;

void apply(int p, int c) {
	t[p] = sum_pw[t[p].r - t[p].l] * c % MD;
	if(p < n) t[p].d = c;
}

void pushdown(int p) {
	for(int _h = h; _h > 0; --_h) {
		int _p = p >> _h;
		if(_p > 0 && t[_p].d > 0) {
			apply(_p << 1, t[_p].d);
			apply(_p << 1 | 1, t[_p].d);
			
			t[_p].d = 0;
		}
	}
}

void pushup(int p) {
	while(p > 1) p >>= 1, t[p].h = (t[p << 1].h * pw[t[p << 1 | 1].r - t[p << 1 | 1].l + 1] + t[p << 1 | 1].h) % MD;
}

void update(int l, int r, int c) {
	int _l, _r;
	_l = (l += n), _r = (r += n);
	
	pushdown(l);
	pushdown(r - 1);
	
	for(; l < r; l >>= 1, r>>= 1) {
		if(l & 1) apply(l++, c);
		if(r & 1) apply(--r, c);
	}
	
	pushup(_l);
	pushup(_r - 1);
}

void query(int l, int r) {
	int _l = l, _r = r;
	l += n, r += n;
	
	pushdown(l);
	pushdown(r - 1);
	
	int hash = 0;
	for(; l < r; l >>= 1, r>>= 1) {
		if(l & 1) hash += t[l].h * pw[_r - 1 - t[l].r] % MD,hash %= MD, l++;
		if(r & 1) --r, hash += t[r].h * pw[_r - 1 - t[r].r] % MD, hash %= MD;
	}
	
	return hash;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	scanf("%s ", s);
	
	int _n = n, _cnt = 0;
	while(_n > 1) _cnt++, _n >>= 1;
	h = cnt;
	
	pw[0] = 1;
	sum_pw[0] = 1;
	for(int i = 1; i < 100005; ++i) pw[i] = pw[i - 1] * P % MD, sum_pw[i] = sum_pw[i - 1] + pw[i] % MD;
	
	for(int i = 0; i < n; ++i) t[n + i].h = s[i] - '0' + 1, t[n + i].l = i, t[n + i].r = i;
	
	for(int i = n - 1; i > 0; --i) {
		t[i] = (t[i << 1] * pw[t[i << 1 | 1].r - t[i << 1 | 1].l + 1] + t[i << 1 | 1]) % MD;
		t[i].l = t[i << 1].l;
		t[i].r = t[i << 1 | 1].r;
	}
	
	for(int i = 0; i < m + k; ++i) {
		int type;
		scanf("%d", &type);
		
		if(type == 1) {
			int l, r, c;
			scanf("%d %d %d", &l, &r, &c);
			update(l - 1, r, c + 1);
		}
		else if(type == 2) {
			int l, r, d;
			scanf("%d %d %d", &l, &r, &d);
			int a = query(l - 1, r - d);
			int b = query(l - 1 + d, r);
			if(a == b) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}
