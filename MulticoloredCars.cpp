#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

map<int, int> m;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, A;
	scanf("%d %d", &n, &A);

	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &tmp);
		if (tmp == A) m[A]++;
		else if (m[tmp] >= m[A]) m[tmp]++;
	}

	if (m[A] == 0) {
		if (A == 1) printf("2");
		else printf("1");
		return 0;
	}

	int min = m[A];
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		pair<int, int> p = *it;
		if (p.second >= min && p.first != A) {
			printf("%d", p.first);
			return 0;
		}
	}

	printf("-1");

	return 0;
}