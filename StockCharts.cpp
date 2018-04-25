#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> VI;

int n, k;
int p[105][30];

VI g[205];
int vis[205];
int match[205];

int dfs(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	
	VI adj = g[u];
	
	for(int v: adj) {
		if(!match[v] || dfs(match[v])) {
			return match[u] = v, match[v] = u, 1;
		}
	}
	
	return 0;
}

int solve() {
	cin >> n >> k;
	
	for(int i = 0; i <= 205; ++i) g[i].clear();
	memset(match, 0, sizeof(match));
	memset(vis, 0, sizeof(vis));
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < k; ++j) {
			int t;
			cin >> t;
			p[i][j] = t;
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(j == i) continue;
			int ok = 1;
			for(int r = 0; r < k; ++r) {
				if(p[i][r] <= p[j][r]) {
					ok = 0;
					break;
				}
			}
			if(ok) g[i].push_back(j + 100);
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		if(!match[i]) memset(vis, 0, sizeof(vis)), dfs(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(!match[i]) ans++;
	}
	
	return ans;
}

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		printf("%d\n", solve());
	}	
	
	return 0;
}
