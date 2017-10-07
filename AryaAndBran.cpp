#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, k;
	scanf("%d %d ", &n, &k);

	int sum = 0;
	int give = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int tmp;
		scanf("%d ", &tmp);
		
		sum += tmp;
		int add = min(sum, 8);
		sum -= add;
		give += add;

		if (give >= k) {
			printf("%d", i + 1);
			return 0;
		}
	}

	printf("-1");


	return 0;
}