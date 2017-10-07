#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;


ll a[100001];


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n;
	scanf("%d ", &n);

	if (n == 0) {
		printf("a");
		return 0;
	}

	int k;
	for (int i = 1; i <= 100000; ++i) {
		int sum = (1 + i) * i / 2;
		a[i] = sum;
		if (sum > 100000) {
			k = i; break;
		}
	}

	int inc = 0;
	while (n > 0) {
		int l = 1, r = k;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (n < a[mid]) r = mid;
			else l = mid + 1;
		}
		if (a[l] != n) l--;
		n -= a[l];
		for (int i = 0; i < l + 1; ++i) printf("%c", 'a' + inc);
		inc++;
	}


	return 0;
}