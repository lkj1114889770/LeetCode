class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0; int left=0;
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            left = max(left,m[s[i]]);
            m[s[i]]=i+1;
            length = max(length,i-left+1);
        }
        return length;
    }
};