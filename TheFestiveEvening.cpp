#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

char S[1000005];
int dp[1000005];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, k;
	scanf("%d %d ", &n, &k);
	scanf("%s ", S);

	for (int i = 0; i < 26; ++i) {
		int s = -1, e = -1;
		for (int j = 0; j < n; ++j) {
			if (S[j] == (char)(65 + i)) {
				s = j;
				break;
			}
		}

		for (int j = n - 1; j >= 0; --j) {
			if (S[j] == (char)(65 + i)) {
				e = j;
				break;
			}
		}

		if (s != -1 && e != -1) {
			for (int j = s; j <= e; ++j) {
				dp[j]++;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (dp[i] > k) {
			printf("YES");
			return 0;
		}
	}

	printf("NO");


	return 0;
}