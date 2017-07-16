#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


int t[200005];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
		scanf("%d", t + i);
	}

	int b2 = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (t[i] == 1) {
			if (a > 0) a--;
			else if (b > 0) {
				b--;
				b2++;
			}
			else if (b2 > 0) b2--;
			else cnt++;
		}
		else if (t[i] == 2) {
			if (b > 0) b--;
			else cnt+=2;
		}
	}

	printf("%d", cnt);

	return 0;
}