4Sum 四数之和

----------
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.

	Example:
	Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
	
	A solution set is:
	[
	  [-1,  0, 0, 1],
	  [-2, -1, 1, 2],
	  [-2,  0, 0, 2]
	]


----------
与[015三数之和类似](/solution/015.3Sum)，这里只是做了转换，从四数之和变为了三数之和，但是处理重复元组的方法不太一样，没有采用变量来记录前一次的值，因为已经排序好，所以直接与相邻的元素比较（除去第一次外），相同就跳过，这样就可以满足条件，可以细细理解下面的去重处理。

	class Solution {
	public:
	    vector<vector<int>> fourSum(vector<int>& nums, int target) {
	        vector<vector<int>> res;
	        if(nums.size()<4) return res;
	        sort(nums.begin(),nums.end());
	        
	        for(int i=0;i<nums.size()-3;i++){
	            if(i>0 && nums[i]==nums[i-1]) continue; //第一个数相同就不再重复用了
	            int newTarget = target - nums[i]; //固定第一个数，将四数之和转换成三数之和
	            for(int j=i+1;j<nums.size()-2;j++){
	                if(j>i+1 &&nums[j]==nums[j-1]) continue; //第二个数，去重
	                int l=j+1,r=nums.size()-1;
	                while(l<r){
	                    if(nums[j]+nums[l]+nums[r]==newTarget){
	                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
	                        while(l<r && nums[l]==nums[l+1]) l++; //第三个数，去重
	                        while(l<r && nums[r]==nums[r-1]) r--; //第四个数，去重
	                        l++;
	                        r--;
	                    }
	                    else if(nums[j]+nums[l]+nums[r]>newTarget) r--;
	                    else l++;
	                }
	            }
	        }
	        
	        return res;
	    }
	};