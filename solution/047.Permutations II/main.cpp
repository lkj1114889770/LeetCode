class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.empty()) return res;
		sort(nums.begin(), nums.end());
		vector<int> re;
		vector<bool> visited(nums.size(), false);
		DFS(res, re, nums, visited);
		return res;
	}
	void DFS(vector<vector<int>>& res, vector<int>&re, vector<int>& nums, vector<bool>& visited){
		if (re.size() == nums.size()){
			res.push_back(re);
			return;
		}

		for (int i = 0; i<nums.size(); i++){
			if (visited[i]) continue;
			if (i>0 && nums[i] == nums[i - 1] && !visited[i - 1])
				continue;  //这种情况针对相同元素，如果后面的元素和前面相同，前面的元素还未访问，那么跳过这种情况
			// 即，相同元素的话，排列的时候保持原序列的前后次序不变，那么就是相同元素对应一种情况
			re.push_back(nums[i]);
			visited[i] = true;
			DFS(res, re, nums, visited);
			visited[i] = false;
			re.pop_back();
		}
	}
};