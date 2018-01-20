/*
input
3
2 6 3
4
1 1 2 2
1 1 3 3
2 1 9
1 1 3 2
output
YES
YES
NO
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int a[500005];
int t[1000005];

int n, h;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void pushup(int p, int y) {
	while(p > 1) p >>= 1, t[p] = gcd(t[p << 1], t[p << 1 | 1]);
}

void update(int p, int y) {
	t[p += n] = y;
	pushup(p, y);
}

int check(int p, int x) {
	if(p >= n) return 1;
	if(t[p << 1] % x == 0 && t[p << 1 | 1] % x == 0) return 1;
	else if(t[p << 1] % x != 0 && t[p << 1 | 1] % x != 0) return 0;
	else if(t[p << 1] % x != 0) return check(p << 1, x);
	else if(t[p << 1 | 1] % x != 0) return check(p << 1 | 1, x);
}

int query(int l, int r, int x) {
	int cnt = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		int a, b;
		if(l & 1) if(t[l++] % x != 0) {
			cnt++;
			if(!check(l - 1, x)) cnt++;
		}
		if(r & 1) if(t[--r] % x != 0) {
			cnt++;
			if(!check(r, x)) cnt++;
		}
		
		if(cnt > 1) break;
	}

	if(cnt > 1) printf("NO\n");
	else printf("YES\n");
}

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	
	for(int i = 0; i < n; ++i) t[n + i] = a[i];
	
	for(int i = n - 1; i > 0; --i) t[i] = gcd(t[i << 1], t[i << 1 | 1]);
	
	int q;
	scanf("%d", &q);
	
	int _n = n, _cnt = 0;
	while(_n > 1) _cnt++, _n >>= 1;
	h = _cnt;
	
	for(int i = 0; i < q; ++i) {
		int type;
		scanf("%d", &type);
		
		if(type == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			
			query(l - 1, r, x);
		}
		else if(type == 2) {
			int p, y;
			scanf("%d %d", &p, &y);
			
			update(p - 1, y);
		}
	}
	
	return 0;
}