#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;


char res[10000005];
char pat[1000005];


int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int k, tmp;
		scanf("%s %d ", pat, &k);
		int ln = strlen(pat);
		int dup = 1;
		for (int j = 1; j < ln; ++j)
			if (pat[j] != pat[j - 1]) dup = 0;

		int lp = 0;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &tmp);
			if (dup && j > 0 && tmp < lp + ln) {
				for (int m = lp + ln; m < tmp + ln; ++m) {
					res[m] = pat[0];
				}
				if (tmp + ln > max) max = tmp + ln;
			}
			else {
				for (int m = 0; m < ln; ++m) {
					res[tmp + m] = pat[m];
				}
				if (tmp + ln > max) max = tmp + ln;
			}

			lp = tmp;
		}
	}

	for (int i = 0; i < max; ++i) {
		if (res[i] == 0) res[i] = 'a';
	}

	printf("%s", res + 1);

	return 0;
}