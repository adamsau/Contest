#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

VI a;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, k, cnt = 0;
	scanf("%d %d ", &n, &k);


	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		scanf("%d ", &tmp);
		a.pb(tmp);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; ++i) {
		while (k < (int)ceil((double)a[i]/2)) {
			k *= 2;
			cnt++;
		}
		if (k < a[i]) k = a[i];
	}

	printf("%d", cnt);

	return 0;
}