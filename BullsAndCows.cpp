#include <bits/stdc++.h>

using namespace std;
string solve(string secret, string guess) {
	int b = 0;
	int c = 0;
	int dp[10] = { 0 };
	int n = secret.length();

	for (int i = 0; i < n; ++i) {
		dp[secret[i] - 48]++;
	}

	for (int i = 0; i < n; ++i) {
		if (dp[guess[i] - 48] > 0) {
			c++;
			dp[guess[i] - 48]--;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (secret[i] == guess[i]) b++;
	}

	c -= b;

	string res = "" + to_string(b) + "A" + to_string(c) + "B";

	return res;
}
class Solution {
public:
	string getHint(string secret, string guess) {
		return solve(secret, guess);
	}
};

/*int main() {
	string s = solve("1807", "7810");
	printf("%s", s.c_str());
}*/