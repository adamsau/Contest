#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


int** dp;
int isEmpty = 0;

void init(VVI& matrix) {
	int r = matrix.size();
	if (r == 0) {
		isEmpty = 1;
		return;
	}
	int c = matrix[0].size();

	isEmpty = 0;
	if (r == 0 || c == 0) {
		isEmpty = 1;
		return;
	}


	dp = new int*[r + 3];
	for (int i = 0; i < r + 3; ++i) {
		dp[i] = new int[c + 3];
		for (int j = 0; j < c + 3; ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
}

int solve(int x1, int y1, int x2, int y2) {
	if (isEmpty) return 0;
	return dp[x2 + 1][y2 + 1] - dp[x1][y2 + 1] - dp[x2 + 1][y1] + dp[x1][y1];
}

/*int main() {
VVI matrix = { {-4, -5} };

init(matrix);

int ret = solve(0, 0, 0, 1);

printf("%d\n", ret);

return 0;
}*/

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		init(matrix);
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return solve(row1, col1, row2, col2);
	}
};