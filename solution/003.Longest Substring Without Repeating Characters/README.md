基本思路就是采取一个滑窗，一个字符一个字符遍历，比如针对"abcabcbb",遍历a,b,c之后又出现了a那么就应该去掉第一次出现的a,然后又出现b,再去掉第一次出现的b，这样最后得到的最长长度为3，我们需要记录出现的字符以及字符对应的位置，采用HashMap来建立字符和位置之间出现的映射，通过滑动窗口，窗口中都是没有重复的字符，每次更新每个字符最后出现的位置，对滑动窗口记录一个左边界left，右边界就是当前遍历到的位置。这样当遍历到一个字符的时候，如果从未在滑窗中出现，那么就可以继续扩大右边界；当出现过在滑窗中，当时当前并未在滑窗内，这种也可以继续扩大右边界；曾经出现过，且在滑窗内，这个时候就需要更新左边界；采用HashMap数据结构的话，前述3种逻辑都可以用一个语句实现：

	left = max(left,m[s[i]]);

未出现过HashMap中读取的value为0，在滑窗之外left>m[s[i]]，都不会更新left，只有在滑窗内left<m[s[i]],才会更新滑窗，完整的解答为：

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

解释一下为什么用到m[s[i]],这里参考了一下博客才知道，HashMap数据集访问不存在的key的时候，会自动采用默认函数进行初始化后返回对应的value，因为int的初始化为0，所以没有初始化赋值直接访问的元素返回初值0。

**参考**

[https://www.cnblogs.com/ariel-dreamland/p/8668286.html](https://www.cnblogs.com/ariel-dreamland/p/8668286.html "https://www.cnblogs.com/ariel-dreamland/p/8668286.html")

[https://blog.csdn.net/qq_29108585/article/details/70142940](https://blog.csdn.net/qq_29108585/article/details/70142940 "https://blog.csdn.net/qq_29108585/article/details/70142940")