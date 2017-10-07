#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int a[1000005];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);

	int odd = 0, even = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d ", a + i);
		if (a[i] % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}

	if (even == n) {
		printf("Second");
	}
	else if (odd == n) {
		printf("First");
	}
	else {
		printf("First");
	}



	return 0;
}