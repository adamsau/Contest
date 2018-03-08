/*
tictictactac
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

typedef vector<int> VI;

char s[5005];

int dp[26][5005][26];

int main() {
    scanf("%s", &s);

    int n = strlen(s);

    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            dp[s[i] - 'a'][j][s[(i + j) % n] - 'a']++;
        }
    }

    int cnt = 0;
    for(int i = 0; i < 26; ++i) {
        int mx = 0;
        for(int j = 1; j < n; ++j) {
            int ok = 0;
            for(int k = 0; k < 26; ++k) {
                if(dp[i][j][k] == 1) {
                    ok++;
                }
            }

            mx = max(mx, ok);
        }

        cnt += mx;
    }

    printf("%.7lf", (double) cnt / n);


	return 0;
}   