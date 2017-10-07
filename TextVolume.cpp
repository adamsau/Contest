#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

char S[205];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%c", S + i);
	}

	int cnt = 0;
	int gmax = 0;
	for (int i = 0; i < n; ++i) {
		if (S[i] >= 'A' && S[i] <= 'Z') cnt++;
		if (S[i] == ' ') {
			gmax = max(gmax, cnt);
			cnt = 0;
		}
	}

	gmax = max(gmax, cnt);

	printf("%d", gmax);


	return 0;
}