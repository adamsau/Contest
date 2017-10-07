#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

VI a;
VPII b;
int c[200005];


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int m;
	scanf("%d ", &m);
	int tmp;
	for (int i = 0; i < m; ++i) {
		scanf("%d ", &tmp);
		a.pb(tmp);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d ", &tmp);
		b.pb(PII(tmp, i));
	}

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());

	for (int i = 0; i < m; ++i) {
		c[b[i].second] = a[i];
	}

	for (int i = 0; i < m; ++i) {
		printf("%d ", c[i]);
	}

	return 0;
}