Longest Palindromic Substring（最长回文子串）

----------

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:

	Input: "babad"
	Output: "bab"
	Note: "aba" is also a valid answer.

Example 2:

	Input: "cbbd"
	Output: "bb"


----------
采用动态规划的方法，字符串s[i，...，j]为回文子串，那么ds[i,j]==1,这样就将回文子串分解为子问题用动态规划求解，状态转移方程为：

	ds[i,j]=1, if ds[i+1,j-1]=1 and s[i]=s[j]
	ds[i,j]=0, if s[i]!=s[j]

且有初始状态：

	ds[i,i]=1
	ds[i,i+1]=1, if s[i]=s[i+1]

采用一个二维数组ds来记录结果，嵌套两层循环，最外层为子串长度，内层为子串起点，每次均只检查子串首尾元素是否相同，且是否满足ds[i-1,j-1]==1

----------

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