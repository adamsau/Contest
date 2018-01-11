/*
input
12 17 9 40
output
32.8333333333
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef priority_queue<ll, vector<ll>, greater<ll>> PQ;

PQ pq;

int main() {
	ll n, m, r, k;
	scanf("%d %d %d %d", &n, &m, &r, &k);
	
	ll sum = 0;
	for(ll i = 0; i < n; ++i) {
		for(ll j = 0; j < m; ++j) {
			int h = 0, v = 0;
			if(i - 0 + 1 >= r) h = min(r, n - i + 1);
			else if(n - i + 1 >= r) h = min(r, i - 0 + 1);
			if(j - 0 + 1 >= r) v = min(r, m - i + 1);
			else if(m - j + 1 >= r) v = min(r, j - 0 + 1);
			
			ll p = v * h;
			sum += p;
			
			//if(pq.size() < k) pq.push(p);
			//else if(p > pq.top()) pq.pop(), pq.push(p);
		}
	}
	
	ll dd = 0;
	for(ll i = 0; i < k; ++i) {
		//dd += pq.top(), pq.pop();
	}
	
	printf("%lf", ((double) dd / sum));
	
	return 0;
}
