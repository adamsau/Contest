#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve(ll a, ll b) {
	ll cr = pow(a * b, (double)1 / 3);
	ll cr2 = cr + 1;
	ll q;
	if (cr * cr * cr == a * b) {
		q = cr;
	}
	else if (cr2 * cr2 * cr2 == a * b) {
		q = cr2;
	}
	else {
		printf("No\n");
		return;
	}
	
	if (a / q >= 1 && b / q >= 1 && a % q == 0 && b % q == 0) {
		printf("Yes\n");
		return;
	}

	printf("No\n");
	return;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);

	ll a, b;
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld ", &a, &b);
		/*int d = gcd(a, b);

		int q1 = a / d;
		int q2 = b / d;

		if (q1 <= d && q2 <= d && q1 * q2 == d) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}*/
		solve(a, b);


	}


	return 0;
}