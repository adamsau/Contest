#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

VI a;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, k;
	scanf("%d %d ", &n, &k);

	for (int i = 0; i < k; ++i) {
		int tmp;
		scanf("%d ", &tmp);
		a.pb(tmp);
	}

	sort(a.begin(), a.end(), greater<int>());

	int four = n;
	int two = 2 * n;
	int fOne = 0;
	int fTwo = 0;

	for (int i = 0; i < k; ++i) {
		int v = a[i];
		while (v > 0) {
			if (v <= 2) {
				if (two) {
					two--;
					v -= min(2, v);
				}
				else if (v == 1 && fOne) {
					fOne--;
					v = 0;
				}
				else if (v <= 2 && fTwo) {
					fTwo--;
					v = 0;
				}
				else if (four) {
					four--;
					int vv = min(4, v);
					if (vv == 2) {
						fOne++;
					}
					else if (vv == 1) {
						fTwo++;
					}
					v -= vv;
				}
				else {
					printf("NO");
					return 0;
				}
			}
			else {
				if (four) {
					four--;
					v -= min(4, v);
				}
				else if (two) {
					two--;
					v -= min(2, v);
				}
				else {
					printf("NO");
					return 0;
				}
			}
		}
	}

	printf("YES");




	return 0;
}