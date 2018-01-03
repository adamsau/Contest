#include <iostream>
#include <algorithm>
#include <vector>

struct B {
	int a;
	int p;
};

struct W {
	int i;
	int j;
	int k;
	int p;
};

using namespace std;

typedef vector<W> VW;
typedef vector<B> VB;

int t[60005];
int ans[200005];
VB vb;
VW vw;
int n;
int q;

bool comp_b(B &b1, B &b2) {
	return b1.a < b2.a;
}
bool comp_w(W &w1, W &w2) {
	return w1.k < w2.k;
}

void init() {
	for(int i = 0; i < n; ++i) t[n + i] = 1;
	for(int i = n - 1; i >= 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

void update(int p, int v) {
	t[n + p] = v;
}

void build(int p) {
	for(int i = p + n; i > 1; i >>= 1) {
		t[i >> 1] = t[i] + t[i ^ 1];
	}
}

int query(int l, int r) {
	int sum = 0;
	for(l += n, r+= n; l < r; l >>= 1, r >>= 1) {
		if(l & 1) sum += t[l++];
		if(r & 1) sum += t[--r];
	}
	
	return sum;
}

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		
		B b = B();
		b.a = a;
		b.p = i;
		
		vb.push_back(b);
	}
	
	scanf("%d", &q);
	
	for(int i = 0; i < q; ++i) {
		int ii, jj, kk;
		scanf("%d %d %d", &ii, &jj, &kk);
		W w = W();
		w.i = ii, w.j = jj, w.k = kk, w.p = i;
		
		vw.push_back(w);
	}
	
	sort(vb.begin(), vb.end(), comp_b);
	sort(vw.begin(), vw.end(), comp_w);
	
	init();
	
	int ind = 0;
	for(int i = 0; i < q; ++i) {
		W w = vw[i];
		for(; ind < n && vb[ind].a <= w.k; ++ind) {
			B b = vb[ind];
			update(b.p, 0);
			build(b.p);
		}
		
		ans[w.p] = query(w.i - 1, w.j);
	}
	
	for(int i = 0; i < q; ++i) {
		printf("%d\n", ans[i]);
	}
	
	return 0;
}
