#include <iostream>

using namespace std;

int n, m, k;

int a[1000005];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		
		a[t] = 1;
	}
	
	int c = 0;
	int ans = 0;
	for(int i = 1; i <= 1e6; ++i) {
		if(i - m >= 1) c -= a[i - m];
		if(a[i]) {
			if(c == k - 1) ans++, a[i] = 0;
			else c++;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
