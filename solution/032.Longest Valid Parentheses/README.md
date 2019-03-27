32.Longest Valid Parentheses 最长有效括号

----------

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:

	Input: "(()"
	Output: 2
	Explanation: The longest valid parentheses substring is "()"

Example 2:

	Input: ")()())"
	Output: 4
	Explanation: The longest valid parentheses substring is "()()"

----------
采用栈的方式，碰到'("压栈，碰到')'出栈，当然压入的不是'('字符，而是对应的下标，这样就有下标信息。起初还是犯了很多错误，主要有：

	()(()

这种情况，就不应该将第一组括号算进来，所以需要维护一个有效括号字符串起始位置start，碰到栈为空的说明没有元素匹配，就需要更新起始位置start；还有就是下面这种情况：

	(()()

这种情况就是起始的第一个(没有括号进行匹配，因为栈也不为空，所以应该用当前位置减去栈顶保存的下标来计算长度。

----------

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