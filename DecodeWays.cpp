#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int dp[3];
int solve(string s) {
	if (s.length() == 0 || s[0] == '0') return 0;
	if (s.length() == 1) return 1;

	dp[0] = 1;
	if (s[1] != '0') dp[1] = 1;
	if (s[0] == '1' || (s[0] == '2' && s[1] >= '0' && s[1] <= '6')) dp[1] += 1;
	if (s.length() == 2) return dp[1];

	for (int i = 2; i < s.length(); ++i) {
		dp[2] = 0;
		if(s[i] != '0') dp[2] = dp[1];
		if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) dp[2] += dp[0];

		for (int j = 1; j < 3; ++j) {
			dp[j - 1] = dp[j];
		}
	}

	return dp[2];
}

/*int main() {
	string s = "1029";

	int ret = solve(s);

	printf("%d", ret);

	return 0;
}*/

class Solution {
public:
	int numDecodings(string s);
};

int Solution::numDecodings(string s) {
	return solve(s);
}