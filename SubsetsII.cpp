#define pb(V) push_back(V)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;

void solve(VI& nums, VVI& res) {
	sort(nums.begin(), nums.end());

	res.pb(VI());

	if (nums.size() == 0) return;

	VI first = VI();
	first.pb(nums[0]);
	res.pb(first);

	int dcnt = 1;
	for (int i = 1; i < nums.size(); ++i) {
		int n = res.size();
		dcnt++;
		if (nums[i] != nums[i - 1]) dcnt = 1;

		for (int j = 0; j < n; ++j) {
			VI p = res[j];
			if (nums[i] == nums[i - 1]) {
				int dcnt2 = 0;
				for (int k = p.size() - 1; k >= 0; --k) {
					if (p[k] == nums[i]) dcnt2++;
				}
				if (dcnt2 == dcnt - 1) {
					VI tmp = VI(p);
					tmp.pb(nums[i]);
					res.pb(tmp);
				}
			}
			else {
				VI tmp = VI(p);
				tmp.pb(nums[i]);
				res.pb(tmp);
			}
		}
	}
}

/*int main() {
	VI nums = { 1, 2, 2 };

	VVI res = VVI();

	solve(nums, res);
	
	for (int i = 0; i < res.size(); ++i) {
		VI p = res[i];
		for (int j = 0; j < p.size(); ++j) {
			printf("%d ", p[j]);
		}
		printf("\n");
	}

	return 0;
}*/

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums);
};

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
	VVI res = VVI();

	solve(nums, res);

	return res;
}