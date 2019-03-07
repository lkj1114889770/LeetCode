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