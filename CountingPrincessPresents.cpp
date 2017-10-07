#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef vector<ll> VLL;

VI g[100005];
int mark[100005];
int visit[100005];
int s = -1;
VLL mul;

#define pb(V) push_back(V)

ll mod = 1e9 + 7;

void dfs0(int n) {
	VI adj = g[n];

	for (int i = 0; i < adj.size(); ++i) {
		int v = adj[i];
		if (!visit[v]) {
			visit[v] = 1;
			dfs0(v);
		}
	}

	if (s == -1 && mark[n]) s = n;
}

int dfs1(int n) {
	VI adj = g[n];

	for (int i = 0; i < adj.size(); ++i) {
		int v = adj[i];
		if (!visit[v]) {
			visit[v] = 1;
			mark[n] |= dfs1(v);
		}
	}

	return mark[n];
}

ll dfs2(int n) {
	VI adj = g[n];

	ll cnt = 0;

	ll c[] = { 0, 0 };
	ll ptr = 0;

	for (int i = 0; i < adj.size(); ++i) {
		int v = adj[i];
		if (!visit[v]) {
			visit[v] = 1;
			c[ptr++] = dfs2(v);
		}
	}

	cnt += 1 + c[0] + c[1] + c[0] * c[1];
	cnt %= mod;

	if (mark[n]) {
		if (cnt != 1) mul.pb(cnt);
		return 0;
	}

	return cnt;
}

void solve() {
	int n;
	scanf("%d ", &n);
	int u, v, w;
	for (int i = 1; i < n; ++i) {
		scanf("%d %d %d ", &u, &v, &w);
		if (w == 1) {
			mark[u] = 1;
			mark[v] = 1;
		}
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 0; i < 100005; ++i) visit[i] = 0;
	visit[1] = 1;
	dfs0(1);
	for (int i = 0; i < 100005; ++i) visit[i] = 0;
	visit[s] = 1;
	dfs1(s);
	for (int i = 0; i < 100005; ++i) visit[i] = 0;
	visit[s] = 1;
	dfs2(s);
	ll res = 1;
	for (int i = 0; i < mul.size(); ++i) {
		res *= mul[i];
		res %= mod;
	}

	printf("%lld\n", res);
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d ", &t);
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < 100005; ++j) {
			g[j].clear();
			visit[j] = 0;
			mark[j] = 0;
		}
		s = -1;
		mul.clear();
		solve();
	}
}
