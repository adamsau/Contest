/*
inputCopy
3
4
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

int a, b;
int main() {
    scanf("%d %d", &a, &b);

    if(a > b) {
        int t = a;
        a = b;
        b = t;
    }

    int ans = 0;
    for(int i = 1 ;a < b; ++i) {
        ans += i;
        ++a;
        if(a < b) {
            ans += i;
            --b;
        }
    }

    printf("%d", ans);

	return 0;
}