#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<char, int > PCI;

char s[100005];
stack<PCI> stk;
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n;
	scanf("%d ", &n);
	scanf("%s", s);

	for (int i = 0; i < n * 2; ++i) {
		PCI pci = PCI(s[i], i);

		if (s[i] == '(') stk.push(pci);
		if (s[i] == ')') {
			if (stk.size() == 0) { stk.push(pci); continue; }
			PCI top = stk.top();
			if (top.first == '(') stk.pop();
			else stk.push(pci);
		}
	}

	int sum = 0;
	int ss = stk.size();
	for (int i = 0; i < ss; ++i) {
		PCI top = stk.top();


		if (top.first == '(') sum += top.second;
		if (top.first == ')') sum -= top.second;

		stk.pop();
	}

	printf("%d", sum);



	return 0;
}