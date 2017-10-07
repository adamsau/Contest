#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

char g[105][105];
char g2[105][105];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, m;
	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%s ", g[i]);
	}

	int R = 0, G = 0, B = 0;
	int lr = 0, lg = 0, lb = 0;
	int cr = 0, cg = 0, cb = 0;
	
	for (int i = 0; i < m; ++i) {
		if (g[0][i] == 'R') R++, lr = i;
		if (g[0][i] == 'G') G++, lg = i;
		if (g[0][i] == 'B') B++, lb = i;
	}

	if (R == 0 || G == 0 || B == 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				g2[m - j - 1][i] = g[i][j];
			}
		}

		int tmp = n;
		n = m;
		m = tmp;

		R = G = B = lr = lg = lb = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				g[i][j] = g2[i][j];
			}
		}

		for (int i = 0; i < m; ++i) {
			if (g[0][i] == 'R') R++, lr = i;
			if (g[0][i] == 'G') G++, lg = i;
			if (g[0][i] == 'B') B++, lb = i;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < R; ++j) {
			if (lr - j >= 0 && g[i][lr - j] == 'R') cr++;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < G; ++j) {
			if (lg - j >= 0 && g[i][lg - j] == 'G') cg++;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < B; ++j) {
			if (lb - j >= 0 && g[i][lb - j] == 'B') cb++;
		}
	}

	if (cr == cb && cb == cg && cr + cb + cg == n * m) {
		printf("YES");
	}
	else {
		printf("NO");
	}




	return 0;
}