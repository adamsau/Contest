/*
input
2
4 2
output
2
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
int n;
VI a;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		
		a.push_back(t);
	}
	
	sort(a.begin(), a.end(), greater<int>());
	
	for(int i = 0; i < n; ++i) {
		int ok = 0;
		for(int j = 1; j <= 1000; ++j)
			if(j * j == a[i]) { ok = 1; break;}
		
		if(!ok) {printf("%d", a[i]); break;}
	}
	return 0;
}