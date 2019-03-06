3Sum 三数之和
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:

	Given array nums = [-1, 0, 1, 2, -1, -4],
	
	A solution set is:
	[
	  [-1, 0, 1],
	  [-1, -1, 2]
	]


----------
最简单粗暴的方式是3层循环遍历，里面加判断，这样复杂度比较高。简单点的思路是，首先将数组排序，因为和为0，如三个元素分别从左到右的话，a<=b<=c,所以a不可能大于0.所以第一个判断nums[i]>0，然后就是典型的两边往中间靠的策略，在i右侧寻找另两个元素，满足nums[l]+nums[r]=-nums[i]，和大于0则r往左r--，和小于0则l往右l++；为了保证没有重复三元组，需要在第一个循环首先保证第一个元素和以前记录的不同，另一个是在第二个循环中保证第二个元素不同。


----------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        vector<int> abc(3);
        
        sort(nums.begin(),nums.end());  //先排个序，从小到大
        int ip=nums[0]-1; //为了不重复,记录每一次第一个元素的值,初始-1肯定不会一样了
        for(int i=0;i<nums.size()-2;i++){
            if(ip==nums[i] || nums[i]>0) continue;  //第一个元素值和前一次相同或者大于0，就跳过
            ip = nums[i]; //更新一下第一个元素前一次记录值
            int l=i+1,r=nums.size()-1;
            int lp = nums[l]-1; //为了不重复，记录第二个元素值，初始-1也会不一样
            while(l<r){
                if((nums[l]+nums[r]+nums[i])==0 && lp!=nums[l]){  //满足和为0，且第二个元素不同
                    abc[0]=nums[i];
                    abc[1]=nums[l];
                    abc[2]=nums[r];
                    res.push_back(abc);
                    lp=nums[l];
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]+nums[i]>0) r--;
                else l++;
            }
        }
        
        return res;
    }
};