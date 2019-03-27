class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<2) return 0;
        int maxLen=0,start=0;
        stack<int> ss;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                ss.push(i);
            else{
                if(ss.empty()){  //栈为空，有效括号结束，更新起始位置
                    start=i+1;
                    continue;
                }
                else{
                    ss.pop();
					//栈为空，但是可能还会有有效括号，先用起始位置更新一下最大长度
                    if(ss.empty()) maxLen=max(maxLen,i-start+1); 
					//栈不为空，说明有左括号'('多余，那就用栈顶元素来计算长度，表明前面已经有的有效长度
                    else maxLen=max(maxLen,i-ss.top()); 
                }
            }
        }
        return maxLen;
    }    
};