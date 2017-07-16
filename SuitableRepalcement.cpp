#define pb(V) push_back(V)

#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

char s[1000005];
char t[1000005];
int sc[26];
int tc[26];

set<PII> st;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int i = 0, q = 0;

	scanf("%s %s ", s, t);

	int n = strlen(s);

	for (i = 0; i < n; ++i) {
		if (s[i] == '?') { q++; continue; }
		sc[s[i] - 97]++;
	}

	for (i = 0; i < strlen(t); ++i) {
		tc[t[i] - 97]++;
	}

	for (i = 0; i < 26; ++i) {
		if (tc[i] != 0) st.insert(PII(sc[i] / tc[i], i));
	}


	for (i = 0; i < n; ++i) {
		if (s[i] == '?') {
			PII p = *(st.begin());
			s[i] = p.second + 97;
			sc[p.second]++;
			st.insert(PII(sc[p.second] / tc[p.second], p.second));
			st.erase(st.begin());
		}
	}

	printf("%s", s);


	return 0;
}