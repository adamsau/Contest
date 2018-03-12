/*
3
8 4 13
17 2 7
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
typedef long long ll;

typedef struct ND ND;
struct ND {
    ll val;
    ll cnt;
    ND* l;
    ND* r;
};

ll n;
ll a[300005];
ll p[300005];
ll ans[300005];

ND* bt;

int main() {
    scanf("%lld ", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld ", &a[i]);
    for(ll i = 0; i < n; ++i) scanf("%lld ", &p[i]);

    bt = new ND();
    bt -> l = bt -> r = 0;
    bt -> val = bt -> cnt = 0;

    for(ll i = 0; i < n; ++i) {
        ND* curr = bt;
        for(ll j = 29; j >= 0; --j) {
            if(p[i] >> j & 1) {
                if(!curr -> r) {
                    ND* nd = new ND();
                    nd -> l = nd -> r = 0;
                    nd -> val = nd -> cnt = 0;
                    curr -> r = nd;

                }
                curr = curr -> r;
            }
            else {
                if(!curr -> l) {
                    ND* nd = new ND();
                    nd -> l = nd -> r = 0;
                    nd -> val = nd -> cnt = 0;
                    curr -> l = nd;
                }
                curr = curr -> l;
            }
            curr -> cnt++;
        }

        curr -> val = p[i];
    }

    for(ll i = 0; i < n; ++i) {
        ND* curr = bt;
        for(ll j = 29; j >= 0; --j) {
            if(a[i] >> j & 1) {
                if(curr -> r && curr -> r -> cnt > 0) curr = curr -> r;
                else curr = curr -> l;
            }
            else {
                if(curr -> l && curr -> l -> cnt > 0) curr = curr -> l;
                else curr = curr -> r;
            }
            curr -> cnt--;
        }
        ans[i] = a[i] ^ curr -> val;
    }

    for(ll i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }

	return 0;
}