#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

VPII a;
int v[100005];
int l[100005];

char buf[1000005];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);
	
	int t;
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &t);
		a.pb(PII(t, i));
	}

	sort(a.begin(), a.end());

	string res = "";

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i == a[i].second) {
			sprintf(buf, "1 %d\n", a[i].second + 1);
			res.append(buf);
			v[i] = 1;
			cnt++;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!v[i]) {
			int root = i;
			int ptr = 0;
			int next = i;
			l[ptr++] = i;
			v[next] = 1;
			while (a[next].second != root) {
				next = a[next].second;
				l[ptr++] = next;
				v[next] = 1;
			}
			
			sprintf(buf, "%d", ptr);
			res.append(buf);
			for (int j = 0; j< ptr; ++j) {
				sprintf(buf, " %d" , l[j] + 1);
				res.append(buf);
			}
			
			res += "\n";

			cnt ++;
		}
	}

	printf("%d\n", cnt);
	printf("%s", res.c_str());

	return 0;
}