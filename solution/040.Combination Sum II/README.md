组合总和 II

----------
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
**说明**：

- 所有数字（包括目标数）都是正整数。

- 解集不能包含重复的组合。 


**示例 1**:

	输入: candidates = [10,1,2,7,6,1,5], target = 8,
	所求解集为:
	[
	  [1, 7],
	  [1, 2, 5],
	  [2, 6],
	  [1, 1, 6]
	]

**示例 2:**

	输入: candidates = [2,5,2,1,2], target = 5,
	所求解集为:
	[
	  [1,2,2],
	  [5]
	]

----------
典型解法还是深度暴力搜索，采用迭代的方式，这个题的套路可以好好体会，但是这里需要注意的是，因为每个数字在每个组合中只能使用1次，在示例1中，candidates = [10,1,2,7,6,1,5], target = 8，因为[1,7],[7,1]结果相同，所以首先排序一下，不回头查找就不会有这种情况；但是另一种情况又出现，就是两个1都有可能和7搭配，结果为8，这时候就需要去重：

    while(i+1<candidates.size() && candidates[i+1]==candidates[i]){
        i++; //去重
    }

在迭代里面采用了上述语句，但是位置一开始放在迭代函数combination之前，导致会直接跳过1，就没有[1,1,6]这种可能，其实下一个位置还可以出现1，就是当前位置不能再从其他位置找到1替换，所以在替代函数后面，加入上面的去重，不在当前位置再放入相同元素：

	class Solution {
	public:
	    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	        vector<vector<int>> res;
	        if(candidates.empty()) return res;
	        vector<int> re;
	        sort(candidates.begin(),candidates.end());
	        combination(res,re,candidates,target,-1);
	        return res;
	    }
	    
	    void combination(vector<vector<int>>& res, vector<int>& re, vector<int>& candidates, int remain, int start){
	        if(remain==0){
	            res.push_back(re);
	            return;
	        }
	        if(remain<0) return;
	        for(int i=start+1;i<candidates.size();i++){
	            re.push_back(candidates[i]);
	            combination(res,re,candidates,remain-candidates[i],i);
	            re.pop_back();
	            while(i+1<candidates.size() && candidates[i+1]==candidates[i]){
	                i++; //去重
	            }
	        }
	    }
	};