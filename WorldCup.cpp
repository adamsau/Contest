/*
inputCopy
4 1 2
output
1
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> VI;


int dfs(int a, int b) {
    if(a == b) return 0;
    else return dfs(a / 2, b / 2) + 1;
}
int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int x = min(a, b);
    int y = max(a, b);

    int h = 0;
    int _n = n;
    for(;_n > 1; _n >>= 1, ++h);

    int ans = dfs(x - 1, y - 1);
    if(ans == h) printf("Final!");
    else printf("%d", ans);
	return 0;
}