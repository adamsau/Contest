#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int l, r, x, y, k;
	scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);

	l = ceil((double)l / k);
	r = r / k;

	if (l > r) {
		printf("NO");
		return 0;
	}

	if (r < x || l > y) printf("NO");
	else printf("YES");


	return 0;
}	