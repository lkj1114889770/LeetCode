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