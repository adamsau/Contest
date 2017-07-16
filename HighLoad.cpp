#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n, k;
	scanf("%d %d ", &n, &k);
	if (n - k >= 2) printf("3\n");
	else printf("2\n");
	for (int i = 2; i <= n - k; i++) {
		printf("1 %d\n", i);
	}
	int e = n - k + 1;
	for (int i = 1; i <= n - k; i++, e++) {
		printf("%d %d\n", i, e);
	}
	for (int i = 0; i < k - (n - k); i++, e++) {
		printf("1 %d\n", e);
	}



	return 0;
}