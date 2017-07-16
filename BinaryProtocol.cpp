#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

char res[95];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n;
	scanf("%d ", &n);
	char c;
	int p = 0;

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%c", &c);
		if (c == '1') cnt++;
		else if (c == '0') {
			res[p++] = '0' + cnt;
			cnt = 0;
		}
	}

	res[p++] = '0' + cnt;

	printf("%s", res);



	return 0;
}