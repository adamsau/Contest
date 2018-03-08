/*
6
-1 1 1 0 0 -1
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef map<int, int> MII;

MII mp;

int main() {
    int n;
    scanf("%d", &n);

    int mn = 100005;
    int mx = -100005;

    for(int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        mn = min(mn, t);
        mx = max(mx, t);

        mp[t]++;
    }

    if(mx - mn == 2) {
        if(mp[mn + 1] / 2 > min(mp[mn], mp[mx])) {
            int cnt = mp[mn + 1] / 2;
            n -= cnt * 2;
            mp[mn] += cnt;
            mp[mx] += cnt;
            mp[mn + 1] -= cnt * 2;
        }
        else {
            int cnt = min(mp[mn], mp[mx]);
            n -= cnt * 2;
            mp[mn + 1] += cnt * 2;
            mp[mn] -= cnt;
            mp[mx] -= cnt;
        }
    }

    printf("%d\n", n);

    for(int i = mn; i <= mx; ++i) {
        int cnt = mp[i];
        for(int j = 0; j < cnt; ++j) printf("%d ", i);
    }

	return 0;
}