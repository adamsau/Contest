#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

VI g[200005];
int a[200005];
int p[200005];

int max1[200005];
int max2[200005];

int gcd(int a, int b) {
	if (a == 0) return b;
	return b == 0 ? a : gcd(b, a % b);
}

void dfs(int n) {
	VI adj = g[n];

	max1[n] = gcd(max1[p[n]], a[n]);
	max2[n] = max(max1[p[n]], gcd(max2[p[n]], a[n]));

	for (int i = 0; i < adj.size(); ++i) {
		dfs(adj[i]);
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d ", a + i);
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d ", &u, &v);

		g[u].pb(v);
		p[v] = u;
	}

	dfs(1);

	for (int i = 1; i <= n; ++i) {
		printf("%d ", max(max1[i], max2[i]));
	}



	return 0;
}