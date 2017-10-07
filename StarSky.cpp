#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int g2[105][105][15];
int g[105][105][15];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, q, c;
	scanf("%d %d %d ", &n, &q, &c);

	for (int i = 0; i < n; ++i) {
		int x, y, s;
		scanf("%d %d %d ", &x, &y, &s);

		for (int j = 0; j < 10; ++j) {
			g[x][y][j] = (s + j) % (c + 1);
		}
	}

	for (int k = 0; k < 10; ++k) {
		for (int i = 1; i <= 100; ++i) {
			for (int j = 1; j <= 100; ++j) {
				g2[i][j][k] = g[i][j][k] + g2[i - 1][j][k] + g2[i][j - 1][k] - g2[i - 1][j - 1][k];
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int t, x1, y1, x2, y2;
		scanf("%d %d %d %d %d ", &t, &x1, &y1, &x2, &y2);

		t = t % (c + 1);

		int res = g2[x2][y2][t] - g2[x2][y1 - 1][t] - g2[x1 - 1][y2][t] + g2[x1 - 1][y1 - 1][t];

		printf("%d\n", res);
	}


	return 0;
}