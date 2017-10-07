#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;

#define pb(V) push_back(V)

VI g[100005];
int visit[100005];
int trSum[100005];
int trHeight[100005];
int trParent[100005];

int n, a, b, c, v1, v2, v3;

void dfs(int node, int height) {
	trHeight[node] = height;

	VI adj = g[node];

	for (int i = 0; i < adj.size(); ++i) {
		int v = adj[i];
		if (!visit[v]) {
			visit[v] = 1;
			trParent[v] = node;

			dfs(v, height + 1);
		}
	}
}

int findParent(int u1, int u2) {
	int h1 = trHeight[u1];
	int h2 = trHeight[u2];

	if (h1 > h2) {
		int tmp = u1;
		u1 = u2;
		u2 = tmp;
		tmp = h1;
		h1 = h2;
		h2 = tmp;
	}

	int d = h2 - h1;
	int p1 = u1;
	int p2 = u2;
	for (int i = 0; i < d; ++i) {
		p2 = trParent[p2];
	}

	while (p1 != p2) {
		p1 = trParent[p1];
		p2 = trParent[p2];
	}

	return p1;
}

int f1(int va, int vb, int pa, int pb) {
	int sum1 = (trHeight[va] - trHeight[pa]) * a;
	int sum2 = (trHeight[vb] - trHeight[pb]) * a;

	return sum1 + sum2;
}

int f2(int va, int vb, int pa, int pb) {
	int sum11 = (trHeight[va] - trHeight[pa]) * a * 2;
	int sum12 = (trHeight[va] - trHeight[pa]) * b;
	int sum2 = (trHeight[vb] - trHeight[pb]) * a;

	return min(sum11 + sum2, sum12 + sum2);
}

int f3(int va, int pa) {
	int s1 = (trHeight[va] - trHeight[pa]) * a * 3;
	int s2 = (trHeight[va] - trHeight[pa]) * b + (trHeight[va] - trHeight[pa]) * a;
	int s3 = (trHeight[va] - trHeight[pa]) * c;

	return min(min(s1, s2), s3);
}


void solve() {
	scanf("%d ", &n);
	scanf("%d %d %d ", &a, &b, &c);
	scanf("%d %d %d ", &v1, &v2, &v3);

	for (int i = 0; i < n; ++i) {
		g[i].clear();
		visit[i] = 0;
		trParent[i] = 0;
		trHeight[i] = 0;
	}

	int u, v;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d ", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}

	visit[1] = 1;
	dfs(1, 0);

	int p1, p2, p3;
	p1 = findParent(v1, v2);
	p2 = findParent(v2, v3);
	p3 = findParent(v1, v3);


	int res = 0;
	if (p1 != p2 && p1 != p3) {
		res += f1(v1, v2, p1, p1);
		res += f2(p1, v3, p2, p2);
		res += f3(p2, 1);
	}
	else if (p2 != p3 && p2 != p1) {
		res += f1(v2, v3, p2, p2);
		res += f2(p2, v1, p3, p3);
		res += f3(p3, 1);
	}
	else if (p3 != p2 && p3 != p1) {
		res += f1(v1, v3, p3, p3);
		res += f2(p3, v2, p1, p1);
		res += f3(p1, 1);
	}
	else if (p1 == p2 && p2 == p3) {
		res += (trHeight[v1] - trHeight[p1]) * a + (trHeight[v2] - trHeight[p1]) * a + (trHeight[v3] - trHeight[p1]) * a;
		res += f3(p1, 1);
	}

	printf("%d\n", res);
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d ", &t);

	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}
