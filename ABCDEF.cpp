#define pb(V) push_back(V)

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

int S[105];

unordered_map<int, int> def;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) scanf("%d ", S + i);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (S[i] != 0) def[S[i] * (S[j] + S[k])]++;

	int sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				sum += def[S[i] * S[j] + S[k]];

	printf("%d", sum);

	return 0;
}