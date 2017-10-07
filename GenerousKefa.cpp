#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int cnt[26];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, k;

	scanf("%d %d ", &n, &k);

	char c;
	for (int i = 0; i < n; ++i) {
		scanf("%c", &c);
		cnt[c - 'a']++;
	}

	int lmax = 0;
	for (int i = 0; i < 26; ++i) {
		lmax = max(lmax, cnt[i]);
	}

	if (lmax > k) {
		printf("NO");
	}
	else {
		printf("YES");
	}



	return 0;
}