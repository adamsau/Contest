#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

VI a;
char c[100005];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int k;
	scanf("%d ", &k);

	scanf("%s ", c);

	int n = strlen(c);

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int v = (int)c[i] - 48;
		sum += v;
		a.pb(v);
	}

	sort(a.begin(), a.end());

	int i = 0;
	while (sum < k) {
		int lmax;
		lmax = 9 - a[i];
		sum += lmax;
		++i;
	}

	printf("%d", i);




	return 0;
}