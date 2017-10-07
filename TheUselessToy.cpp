#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	char s, e;
	scanf("%c %c ", &s, &e);
	int n;
	scanf("%d ", &n);

	int r = n % 4;

	char p[4] = {'v', '<', '^', '>'};

	int ss;

	for (int i = 0; i < 4; ++i) if (p[i] == s) ss = i;
	if (p[(ss + r + 4) % 4] == e && p[(ss + - r + 4) % 4] == e) {
		printf("undefined");
		return 0;
	}
	if (p[(ss + r + 4) % 4] == e) {
		printf("cw");
		return 0;
	}
	if (p[(ss - r + 4) % 4] == e) {
		printf("ccw");
		return 0;
	}



	return 0;
}