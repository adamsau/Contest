/*
input
4 3
0 1 0 1
0 1
1 2
2 3
output
2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef queue<int> QI;

int n, m;
int w[100005];
VI g[100005];
int ir[100005];
int cf[100005];
int rf[100005];
int cnt[100005];
QI q;

#define pb(v) push_back(v)

void bfs() {
	while(q.size() > 0) {
		int u = q.front();
		
		VI adj = g[u];
		
		for(int i = 0; i < adj.size(); ++i) {
			int v = adj[i];
			cf[v]++;
			cnt[v] = max(cnt[v], w[v] && !w[u] ? cnt[u] + 1 : cnt[u]);
			if(rf[v] == cf[v]) q.push(v);
		}
		
		q.pop();
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i) scanf("%d", &w[i]), ir[i] = 1;

	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &v, &u);
		
		g[u].pb(v);
		ir[v] = 0;
		rf[v]++;
	}
	
	for(int i = 0; i < n; ++i) {
		if(ir[i]) q.push(i); if(ir[i] && w[i]) cnt[i] = 1;
	}
	
	bfs();
	
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, cnt[i]);
	}
	
	printf("%d", ans);
	
	return 0;
}
