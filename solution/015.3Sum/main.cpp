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