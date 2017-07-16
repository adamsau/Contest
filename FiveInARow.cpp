#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

char g[16][16];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j)
			scanf("%c", &g[i][j]);

		scanf(" ");
	}

	for(int i = 0; i < 10; ++i){
		int X = 0;
		int d = 0;
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 5; ++k) {
				if (g[i][j + k] == 'X') X++;
				else if (g[i][j + k] == '.') d++;
			}
			if (X == 4 && d == 1) {
				printf("YES");
				return 0;
			}
			X = d = 0;

			for (int k = 0; k < 5; ++k) {
				if (g[i + k][j] == 'X') X++;
				else if (g[i + k][j] == '.') d++;
			}
			if (X == 4 && d == 1) {
				printf("YES");
				return 0;
			}
			X = d = 0;

			for (int k = 0; k < 5; ++k) {
				if (g[i + k][j + k] == 'X') X++;
				else if (g[i + k][j + k] == '.') d++;
			}
			if (X == 4 && d == 1) {
				printf("YES");
				return 0;
			}
			X = d = 0;

			for (int k = 0; k < 5; ++k) {
				if (i - k < 0) break;
				if (g[i - k][j + k] == 'X') X++;
				else if (g[i - k][j + k] == '.') d++;
			}
			if (X == 4 && d == 1) {
				printf("YES");
				return 0;
			}
			X = d = 0;
		}
	}

	printf("NO");


	return 0;
}