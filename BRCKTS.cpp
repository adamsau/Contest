#include <iostream>
using namespace std;

int sum[60005];
int amin[60005];
int n;

void update(int p) {
	for(amin[p + n] = sum[p + n] *= -1, p += n; p > 0; p >>= 1) {
		sum[p >> 1] = sum[p] + sum[p ^ 1];
		amin[p >> 1] = min(amin[(p | 1) - 1], sum[(p | 1) - 1] + amin[p | 1]);
	}
}

void build() {
	for(int i = n - 1; i > 0; --i) {
		sum[i] = sum[i << 1] + sum[i << 1 | 1];
		amin[i] = min(amin[i << 1], sum[i << 1] + amin[i << 1 | 1]);
	}	
}

int qsum(int l, int r) {
	int s = 0;
	for(l += n, r+= n; r > l; r >>= 1, l >>= 1) {
		if(l & 1) s += sum[l++];
		if(r & 1) s +=sum[--r];
	}
	
	return s;
}

int qmin(int l, int r) {
	int m = 60005;
	for(l += n, r+= n; r > l; r >>= 1, l >>= 1) {
		if(l & 1) m = min(m, amin[l++]);
		if(r & 1) m = min(m, amin[--r]);
	}
	
	return m;
}

void solve() {
	scanf("%d ", &n);
	
	for(int i = 0; i < n; ++i) {
		char c;
		scanf("%c ",&c);
		amin[n + i] = sum[n + i] = (c == '(') ? 1 : -1;
	}
	
	build();
	
	int m;
	scanf("%d ", &m);
	
	for(int i = 0; i < m; ++i) {
		int opr;
		scanf("%d ", &opr);
		if(opr > 0) {
			update(opr - 1);
		}
		else {
			int csum = qsum(0, n);
			int cmin = qmin(0, n);
			if(csum == 0 && cmin >= 0 && sum[n] == 1) {
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
}

int main() {
	// your code goes here
	for(int i = 1; i <= 10; ++i) {
		printf("Test %d:\n", i);
		solve();
	}
	return 0;
}
