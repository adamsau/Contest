#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;

ll f[51];
int g[51][51];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	f[0] = 1;
	for (int i = 1; i <= 50; ++i) {
		f[i] = 2 * f[i - 1];
	}

	int n, m;
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d ", &(g[i][j]));
		}
	}

	ll cnt = n * m;
	int b = 0, w = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 0) w++;
			else b++;
		}
		cnt += (f[w] - 1 - w) + (f[b] - 1 - b);
		b = w = 0;
	}

	b = w = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (g[j][i] == 0) w++;
			else b++;
		}
		cnt += (f[w] - 1 - w) + (f[b] - 1 - b);
		b = w = 0;
	}

	printf("%lld", cnt);


	return 0;
}