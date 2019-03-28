Permutations II（全排列II）

----------

给定一个可包含重复数字的序列，返回所有不重复的全排列。
**示例:**

	输入: [1,1,2]
	输出:
	[
	  [1,1,2],
	  [1,2,1],
	  [2,1,1]
	]


----------
这里本来想参考组合的方法，在原来的数组上进行交换，对发现相邻元素相同跳过的方式，但是由于是全排列，当相同元素打乱之后，再采用相邻元素跳过的方式就不行了，而且也不好再用这种交换的方法，判断起来有点复杂。
返回到最原始的数学问题，对于元素[1,1,1,2],不考虑相同元素有24种排列，考虑相同元素3个1的排列6种，如果将3个1的排列都看成同一种，其实只有4种排列，基于此思路，就是把相同元素的排列固定一种，思路就是，即使相同元素保持排列后前后次序还是不变，即还是从小到大的索引穿插在排列中，那么就在迭代的时候判断一下，相同元素前面的是否已经被访问了，没有的话就是不符合的情况，这样就满足条件了：

	class Solution {
	public:
	    vector<vector<int>> permuteUnique(vector<int>& nums) {
	        vector<vector<int>> res;
	        if(nums.empty()) return res;
	        sort(nums.begin(),nums.end());
	        vector<int> re;
	        vector<bool> visited(nums.size(),false);
	        DFS(res,re,nums,visited);
	        return res;
	    }
	    void DFS(vector<vector<int>>& res, vector<int>&re, vector<int>& nums, vector<bool>& visited){
	        if(re.size()==nums.size()){
	            res.push_back(re);
	            return;
	        }
	        
	        for(int i=0;i<nums.size();i++){
	            if(visited[i]) continue;
	            if(i>0 && nums[i]==nums[i-1] && !visited[i-1])
	                continue;  //这种情况针对相同元素，如果后面的元素和前面相同，前面的元素还未访问，那么跳过这种情况
	                           // 即，相同元素的话，排列的时候保持原序列的前后次序不变，那么就是相同元素对应一种情况
	            re.push_back(nums[i]);
	            visited[i]=true;
	            DFS(res,re,nums,visited);
	            visited[i]=false;
	            re.pop_back();
	        }
	    }
	};


----------
[不含重复元素全排列](https://leetcode-cn.com/problems/permutations/)

对于不含重复元素全排列来说，其实是可以用交换的方式的，因为所有元素不一样：

	class Solution {
	public:
	    vector<vector<int>> permute(vector<int>& nums) {
	        vector<vector<int>> res;
	        if(nums.empty()) return res;
	        permute(res,nums,0,nums.size());
	        return res;
	    }
	    
	    void permute(vector<vector<int>>& res, vector<int>& re,int start,int end){
	        if(start==end-1) {
	            res.push_back(re);
	            return;
	        }
	        for(int i=start;i<end;i++){
	            swap(re[start],re[i]);
	            permute(res,re,start+1,end);
	            swap(re[start],re[i]);
	        }
	    }
	};

当然也可以用类似于47题的用一个额外数组，在原数组上访问来排列的方式，代码类似于47上面的，去掉那个对于重复元素的判断即可。