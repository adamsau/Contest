#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

char c[105][105];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, m;
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%c", &c[i][j]);
		}
		scanf(" ");
	}

	int minr = 105, minc = 105;
	int maxr = -1, maxc = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (c[i][j] = 'B') {
				if (i > maxr) maxr = i;
				if (i < minr) minr = i;
				if (j > maxc) maxc = j;
				if (j < minc) minc = j;
			}
		}
	}

	int side = max(maxr - minr + 1, maxc - minc + 1);

	int cnt = 0;

	printf("%d", cnt);

	return 0;
}