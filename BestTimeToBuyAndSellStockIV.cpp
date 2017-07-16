#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int solve(int k, vector<int>& p) {
	int n = p.size();
	if (k == 0 || n == 0) return 0;

	int **buy = new int*[n + 1];
	int **sell = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		buy[i] = new int[k + 1];
		sell[i] = new int[k + 1];
	}
	 
	for (int i = 1; i <= k; ++i) buy[0][i] = -p[0];

	for (int i = 1; i <= n; ++i) {
		for (int j = k; j >=1; --j) {
			sell[i][j] = max(sell[i - 1][j], buy[i - 1][j] + p[i - 1]);
			buy[i][j] = max(buy[i - 1][j], sell[i - 1][j - 1] - p[i - 1]);
		}
	}

	return sell[n][k];
}


/*int main() {
	int k = 3;
	vector<int> prices = {1, 5, 2, 6, 2, 5};
	int ret = solve(k, prices);

	printf("%d", ret);

	return 0;
}*/

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		return solve(k, prices);
	}
};