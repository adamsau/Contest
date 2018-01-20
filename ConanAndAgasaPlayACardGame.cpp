#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

#define pb(V) push_back(V)
int n;
VI a;

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		a.pb(t);
	}
	
	sort(a.begin(), a.end(), greater<int>());
	
	int c = a[0];
	
	int cnt = 0;
	for(int i = 1; i < n; ++i) {
		if(c == a[i]) cnt++;
		else break;
	}
	
	if(cnt % 2 == 0) printf("Conan");
	else printf("Agasa");
	
	return 0;
}