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

	int n;
	scanf("%d ", &n);

	int tmp;
	for (int i = 0; i < 2 * n; ++i) {
		scanf("%d ", &tmp);
		a.pb(tmp);
	}

	sort(a.begin(), a.end(), greater<int>());

	if (a[n - 1] <= a[n]) {
		printf("NO");
	}
	else {
		printf("YES");
	}

	return 0;
}