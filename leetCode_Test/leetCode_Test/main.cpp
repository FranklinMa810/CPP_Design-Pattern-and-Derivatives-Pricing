#include <iostream>
#include <vector>
using namespace std;




void dfs(vector<int>& nums, int subset_size, int idx, vector<int>& curr, vector<vector<int>>& ans) {
	if (curr.size() == subset_size) {
		ans.push_back(curr);
	    return;
	}
	for (int j = idx; j < nums.size(); ++j) {
		curr.push_back(nums[j]);
		dfs(nums, subset_size, j + 1, curr, ans);
		curr.pop_back();
	}
}

int main(){
	vector<int> nums = { 1, 2, 3 };
	vector<vector<int>> ans;    // answer container, return ans.
	vector<int> curr;    // contain one subset and push it to ans.
	for (int subset_size = 0; subset_size <= nums.size(); ++subset_size)
		dfs(nums, subset_size, 0, curr, ans);
	for (int i = 0; i < ans.size(); ++i){
		for (int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << ",";
			cout << endl;
	}

	return 0;
}