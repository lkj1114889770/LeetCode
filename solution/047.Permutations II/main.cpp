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
				continue;  //������������ͬԪ�أ���������Ԫ�غ�ǰ����ͬ��ǰ���Ԫ�ػ�δ���ʣ���ô�����������
			// ������ͬԪ�صĻ������е�ʱ�򱣳�ԭ���е�ǰ����򲻱䣬��ô������ͬԪ�ض�Ӧһ�����
			re.push_back(nums[i]);
			visited[i] = true;
			DFS(res, re, nums, visited);
			visited[i] = false;
			re.pop_back();
		}
	}
};