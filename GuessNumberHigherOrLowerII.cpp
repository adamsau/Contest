#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int f(int a, int b, int** dp) {
	if (a == b || a > b) return 0;

	if (dp[a][b] != 0) return dp[a][b];

	int mn = LONG_MAX;
	for (int i = a; i <= b; ++i) {
		mn = min(mn, max(i + f(a, i - 1, dp), i + f(i + 1, b, dp)));
	}

	dp[a][b] = mn;
	return dp[a][b];
}

int solve(int n) {
	int ** dp = new int*[n + 3];
	for (int i = 0; i < n + 3; ++i) {
		dp[i] = new int[n + 3]; 
		for (int j = 0; j < n + 3; ++j) {
			dp[i][j] = 0;
		}
	}

	int ret = f(1, n, dp);

	return ret;
}

/*int main() {
	int n = 2;

	int ret = solve(n);

	printf("%d", ret);


	return 0;
}*/

class Solution {
public:
	int getMoneyAmount(int n);
};

int Solution::getMoneyAmount(int n) {
	return solve(n);
}
