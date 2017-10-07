#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int x[105];
int y[105];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int n, a, b;
	scanf("%d %d %d ", &n, &a, &b);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d ", x + i, y + i);
	}

	int gmax = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;

			if (x[i] + x[j] <= a && y[i] <= b && y[j] <= b) {
				gmax = max(gmax, x[i] * y[i] + x[j] * y[j]);
			}

			if (x[i] + y[j] <= a && y[i] <= b && x[j] <= b) {
				gmax = max(gmax, x[i] * y[i] + x[j] * y[j]);
			}

			if (x[i] + x[j] <= b && y[i] <= a && y[j] <= a) {
				gmax = max(gmax, x[i] * y[i] + x[j] * y[j]);
			}

			if (x[i] + y[j] <= b && y[i] <= a && x[j] <= a) {
				gmax = max(gmax, x[i] * y[i] + x[j] * y[j]);
			}
		}
	}

	printf("%d", gmax);


	return 0;
}