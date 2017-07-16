#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int f(VI& p, int s, int e,int ** dp) {
	if (dp[s][e] != -1) return dp[s][e];
	if (s >= e) {
		dp[s][e] = 0;
		return 0;
	}

	int res = p[e] - p[s];
	for (int i = s; i <= e; ++i) {
		res = max(res, f(p, s, i - 1, dp) + f(p, i + 1, e, dp));
	}
	if (res < 0) res = 0;
	dp[s][e] = res;

	return res;
}

int solve(VI& p) {
	int n = p.size();
	if (n < 2) return 0;

	int ** dp = new int*[n + 5];
	for (int i = 0; i < n + 5; ++i) {
		dp[i] = new int[n + 5];
		for (int j = 0; j < n + 5; ++j) dp[i][j] = -1;
	}

	int res = f(p, 0, n - 1, dp);

	if (res < 0) res = 0;

	return res;
}

/*int main() {
	VI p = {1, 2, 3, 0, 2};

	int res = solve(p);

	printf("%d", res);

	return 0;
}*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		return solve(prices);
	}
};