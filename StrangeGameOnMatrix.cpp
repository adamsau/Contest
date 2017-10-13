#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int a[105][105];
int p[105];
int sum[105];
int cnt;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, m, k;
	scanf("%d %d %d ", &n, &m, &k);
	
	for(int i = 0 ; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d ", &a[i][j]);
	
	int total = 0;
	for(int j = 0; j < m; ++j) {
		int s = 0;
		for(int i = 0; i < k; ++i) s += a[i][j];
		sum[j] = s;
		for(int i = k; i < n; ++i) {
			s += a[i][j] - a[i - k][j];
			if(s > sum[j]) {
				sum[j] = s;
				p[j] = i - k + 1;
			}
		}
		total += sum[j];
	}
	
	for(int j = 0; j < m; ++j) {
		for(int i = 0; i < p[j]; ++i) {
			if(a[i][j] == 1) cnt++;
		}
	}
	
	printf("%d %d", total, cnt);

return 0;
}