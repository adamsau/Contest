#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


VI g[100005];
int visit[100005];
int depth[100005];
double prob[100005];
double result[100005];
double tsum = 0;

void dfs(int n) {
	VI adj = g[n];

	int k = 0;

	double sum = 0;
	for (int i = 0; i < adj.size(); ++i) {
		int v = adj[i];
		if (!visit[v]) {
			++k;
		}
	}
	for (int i = 0; i < adj.size(); ++i) {
		int v = adj[i];
		if (!visit[v]) {
			visit[v] = 1;
			prob[v] = prob[n] / k;
			depth[v] = depth[n] + 1;
			dfs(v);
		}
	}

	if (k == 0) {
		double psum =  prob[n] * depth[n];
		result[n] = psum;
		tsum += psum;
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);

	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d ", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}

	visit[1] = 1;
	prob[1] = 1;
	dfs(1);

	printf("%.8f", tsum);



	return 0;
}