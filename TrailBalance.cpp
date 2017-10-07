#include <bits/stdc++.h>

using namespace std;


int val[205];
char type[205];
int dp[10005][205];
int cc[10005][205];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, m;
	scanf("%d %d ", &n, &m);

	int ptr = 0;
	int tmp;
	int tsum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &tmp);
		val[ptr] = tmp;
		type[ptr] = 'd';
		ptr++;
		tsum += tmp;
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d ", &tmp);
		val[ptr] = tmp;
		type[ptr] = 'c';
		ptr++;
		tsum += tmp;
	}

	for (int i = 0; i <= n + m; ++i) dp[0][i] = 1;

	for (int i = 1; i <= tsum; ++i) {
		for (int j = 0; j < n + m; ++j) {
			dp[i][j + 1] = dp[i][j];
			cc[i][j + 1] = cc[i][j];

			if (val[j] > i) continue;

			if (!dp[i][j + 1] && dp[i - val[j]][j]) {
				dp[i][j + 1] = 1;
				if (type[j] == 'd') cc[i][j + 1] = cc[i - val[j]][j] - 1;
				else if (type[j] == 'c') cc[i][j + 1] = cc[i - val[j]][j] + 1;
			}
			else if (dp[i][j + 1] && dp[i - val[j]][j] && (cc[i - val[j]][j] + (type[j] == 'd' ? -1 : 1)) < cc[i][j + 1]) {
				cc[i][j + 1] = cc[i - val[j]][j] + (type[j] == 'd' ? -1 : 1);
			}
		}
	}


	int diff = 10005;
	int steps = n + m;
	for (int i = tsum; i >= 0; --i) {
		if (dp[i][n + m]) {
			int tdiff = tsum - 2 * i;
			int abstdiff = abs(tdiff);
			if (abs(tdiff) < diff) {
				diff = abs(tdiff);
				steps = n + cc[i][n + m];
			}
			else if (abs(tdiff) == diff) {
				steps = min(steps, n + cc[i][n + m]);
			}
		}
	}

	printf("%d %d", diff, steps);

	return 0;
}
