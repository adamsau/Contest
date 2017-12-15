#include <iostream>
using namespace std;

int sum[30005];
int amin[30005];
int n;

void upate(int p) {
	for(sum[p += n] *= -1; p > 0; p >>= 1) {
		sum[p >> 1] = sum[p] + sum[p ^ 1];
		amin[p >> 1] = min(amin[p & 0], sum[p & 0] + amin[p | 1]);
	}
}

void build() {
	for(int i = n - 1; i > 0; --i) {
		sum[i] = sum[i << 1] + sum[i << 1 | 1];
		amin[i] = min(amin[i << 1], sum[i << 1] + amin[i << 1 | 1]);
	}	
}

int query(int l, int r) {
	
}

void solve() {
	scanf("%d ", &n);
	
	for(int i = 0; i < n; ++i) {
		char c;
		scanf("%c ",&c);
		amin[n + i] = sum[n + i] = (c == '(') ? 1 : -1;
	}
	
	build();
}

int main() {
	// your code goes here
	for(int i = 1; i <= 10; ++i) {
		printf("Test %d:\n", i);
		solve();
	}
	return 0;
}
