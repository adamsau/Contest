#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int p[105];
int l[105];
int u[105];
int v[105];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d ", l + i);
	}

	for (int i = 1; i < m; ++i) {
		int pp = l[i] - l[i - 1];
		if (pp <= 0) pp += n;
		if (p[l[i - 1]] != 0 && p[l[i - 1]] != pp) {
			printf("-1");
			return 0;
		}
		p[l[i - 1]] = pp;
	}

	for (int i = 1; i <= n; ++i) {
		u[p[i]]++;
		if (p[i] > 0 && u[p[i]] > 1) {
			printf("-1");
			return 0;
		}
	}

	int ec = 0;
	for (int i = 1; i <= n; ++i) if (!u[i]) v[ec++] = i;
	for (int i = 1; i <= n; ++i) if (!p[i]) p[i] = v[--ec];

	for (int i = 1; i <= n; ++i) printf("%d ", p[i]);


	return 0;
}