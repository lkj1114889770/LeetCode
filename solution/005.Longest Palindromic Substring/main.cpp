class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size()==1) return s;
        int len = s.size();
        int longest = 1, start = 0;
        vector<vector<int> > ds(len,vector<int>(len));
        for(int i=0;i<len;i++){
            ds[i][i]=1;
            if(i<len-1){
                if(s[i]==s[i+1]){
                    ds[i][i+1]=1;
                    start=i;
                    longest=2;
                }
            }
        }
        
        for(int l=3;l<=len;l++) //子串长度
        {
            for(int i=0;i+l-1<len;i++){  //子串起点
                int j=i+l-1; //终点
                if(s[i]==s[j] && ds[i+1][j-1]==1){
                    ds[i][j]=1;
                    longest=l;
                    start=i;
                }
            }
        }
        return s.substr(start,longest);
    }
}