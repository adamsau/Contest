#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int a[105];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) scanf("%d ", a + i);

	int l = 0, r = n - 1;
	int cnt = 0;

	while (l < n) {
		while (!(a[l] % 2 == 1 && a[r] % 2 == 1 && (r - l + 1) % 2 == 1)) {
			r--;
			if (r < l) {
				printf("No");
				return 0;
			}
		}
		cnt++;
		l = r + 1;
		r = n - 1;
	}

	if (cnt % 2 == 1) printf("Yes");
	else printf("No");

	return 0;
}