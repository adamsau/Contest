#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int s, v1, v2, t1, t2;

	scanf("%d %d %d %d %d ", &s, &v1, &v2, &t1, &t2);

	int tt1 = t1 * 2 + s * v1;
	int tt2 = t2 * 2 + s * v2;

	if (tt1 > tt2) {
		printf("Second");
	}
	else if (tt1 < tt2) {
		printf("First");
	}
	else {
		printf("Friendship");
	}


	return 0;
}