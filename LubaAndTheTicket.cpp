#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

VI a;
VI b;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	char tmp;
	for (int i = 0; i < 6; ++i) {
		scanf("%c", &tmp);
		a.pb(tmp - '0');
	}

	int l = 0, r = 0;
	for (int i = 0; i < 3; ++i) {
		l += a[i];
		r += a[i + 3];
	}

	for (int i = 0; i < 3; ++i) {
		int dd = max(abs(9 - a[i]), abs(0 - a[i]));
		b.pb(dd);
	}

	sort(b.begin(), b.end(), greater<int>());

	int p = 0;
	int d = abs(l - r);
	while (d > 0) {
		d -= b[p++];
	}

	printf("%d", p);

	return 0;
}