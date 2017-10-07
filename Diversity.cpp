#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


char s[1005];
int v[26];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	scanf("%s ", s);

	int k;
	scanf("%d ", &k);

	int n = strlen(s);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!v[s[i] - 'a']) {
			v[s[i] - 'a'] = 1;
			cnt++;
		}
	}

	if (cnt >= k) printf("0");
	else if (k <= n) printf("%d", k - cnt);
	else printf("impossible");

	return 0;
}