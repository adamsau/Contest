#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

long md = 1e9 + 7;
int solve(int n) {
	long *** dp = new long**[n + 2];
	for (int i = 0; i < n + 1; ++i) {
		dp[i] = new long*[2];
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = new long[3];
			for (int k = 0; k < 3; ++k) dp[i][j][k] = 0;
		}
	}
	
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][0] = 1;
	dp[2][0][0] = 2;
	dp[2][0][1] = 1;
	dp[2][0][2] = 1;
	dp[2][1][0] = 3;
	dp[2][1][1] = 1;

	for (int i = 3; i <= n; ++i) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % md;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i -  1][1][2]) % md;
		dp[i][1][1] = dp[i - 1][1][0] % md;
		dp[i][1][2] = dp[i - 1][1][1] % md;
	}

	long sum = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			sum += dp[n][i][j];
		}
	}

	return sum;
}

/*int main() {
	int ret = solve(2);

	printf("%ld\n", ret);

	return 0;
}*/

class Solution {
public:
	int checkRecord(int n) {
		return solve(n);
	}
};