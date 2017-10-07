#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

vector<int> sl;
vector<int> ot;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, s;
	scanf("%d ", &n);

	int t, v, cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &t);
		if (t == 1) {
			scanf("%d ", &v);
			s = v;
			while (sl.size() > 0 && s > *sl.begin()) {
				sl.erase(sl.begin());
				cnt++;
			}
		}
		else if (t == 2) {
			while (ot.size() > 0) {
				ot.erase(ot.begin());
				cnt++;
			}
		}
		else if (t == 3) {
			scanf("%d ", &v);
			sl.pb(v);

			sort(sl.begin(), sl.end());
			while (sl.size() > 0 && s > *sl.begin()) {
				sl.erase(sl.begin());
				cnt++;
			}
		}
		else if (t == 4) {
			ot.clear();
		}
		else if (t == 5) {
			sl.clear();
		}
		else if (t == 6) {
			ot.pb(1);
		}
	}

	printf("%d", cnt);

	return 0;
}