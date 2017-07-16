#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums);
};


void f(VI& nums, int s, int e, VVI& res) {
	if (s == e) return;

	int n = res.size();
	for (int i = 0; i < n; ++i) {
		VI p = res[0];

		for (int j = 0; j <= p.size(); ++j) {
			VI tmp = VI(p);
			tmp.insert(tmp.begin() + j, nums[s]);
			res.pb(tmp);

			//if (j < p.size() && tmp[j] == tmp[j + 1]) break;
		}

		res.erase(res.begin());
	}

	f(nums, s + 1, e, res);
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
	VVI res = VVI();
	VI a = VI();
	a.pb(nums[0]);
	res.pb(a);

	f(nums, 1, nums.size(), res);

	return res;
}

/*int main() {
VI nums = {1, 1, 2};

VVI res = VVI();
VI a = VI();
a.pb(nums[0]);
res.pb(a);

f(nums, 1, nums.size(), res);

for (int i = 0; i < res.size(); ++i) {
VI p = res[i];
for (int j = 0; j < p.size(); ++j) {
printf("%d ", p[j]);
}
printf("\n");
}


return 0;
}*/