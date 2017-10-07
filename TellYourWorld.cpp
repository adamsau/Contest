#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

VPII a;

double slope(PII c1, PII c2) {
	return (double)(c2.second - c1.second) / (c2.first - c1.first);
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);

	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &tmp);
		a.pb(PII(i, tmp));
	}
	for (int k = 0; k < 2; ++k)
		for (int i = 0; i < n; ++i) {
			if (i == k) continue;
			double sl1 = slope(a[k], a[i]);
			VPII b = VPII();
			for (int j = 0; j < n; ++j) {
				if (i == j || k == j) continue;
				double sl2 = slope(a[k], a[j]);
				if (sl2 != sl1) {
					b.pb(a[j]);
				}
			}
			if (b.size() == 0) continue;
			else if (b.size() == 1) {
				printf("Yes");
				return 0;
			}

			double sl3 = slope(b[0], b[1]);

			if (sl3 != sl1) continue;

			VPII c = VPII();
			for (int j = 2; j < b.size(); ++j) {
				double sl4 = slope(b[0], b[j]);
				if (sl4 != sl3) c.pb(b[j]);
			}

			if (c.size() == 0) {
				printf("Yes");
				return 0;
			}
		}

	printf("No");
	return 0;
}