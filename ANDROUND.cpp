#include <iostream>
using namespace std;
 
int t[20000 * 2 + 5];
int n;
 
void build() {
	for(int i = n - 1; i >= 0; --i) {
		t[i] = t[2 * i] & t[2 * i + 1];
	}
}
 
int query(int l, int r) {
	int res = t[l + n];
	for(l += n, r += n; r > l; r >>= 1, l >>= 1) {
		if(l & 1) res &= t[l++];
		if(r & 1) res &= t[--r];
		
	}
	
	return res;
}
 
void solve() {
	int k;
	scanf("%d %d ", &n, &k);
	k = min(n, k);
	
	for(int i = 0; i < n; ++i) scanf("%d ", t + n + i);
	build();
	
	for(int i = 0; i < n; ++i) {
		int res = t[i + n];
		
		res &= query(max(0, i - k), min(i + k + 1, n));
		
		if(i - k < 0) {
			res &= query(n - (k - i), n);
		}
		if(i + k + 1 > n) {
			res &= query(0, i + k + 1 - n);
		}
		
		printf("%d ", res);
	}
	
	printf("\n");
}
 
int main() {
	// your code goes here
	int t;
	scanf("%d ", &t);
	
	for(int i = 0; i < t; ++i) solve();
	
	return 0;
} 
