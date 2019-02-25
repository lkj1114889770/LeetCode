There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:

	nums1 = [1, 3]
	nums2 = [2]

	The median is 2.0
Example 2:

	nums1 = [1, 2]
	nums2 = [3, 4]
	
	The median is (2 + 3)/2 = 2.5

============================================
因为有复杂度O(log(m+n))的要求，所以我们采用分治法。首先将nums1，nums2分成划分成两部分拼在一起，初始时候取中间位置划分nums1，再划分nums2，nums1的左半部分和nums2的右半部分拼接，在 
[0，m]中搜索并找到目标对象 i，满足

	B[j−1]≤A[i]，且A[i-1]≤B[j]，其中j=(m+n+1)/2-i;

这时候就会碰到三种情况：
1. i<imax且nums1[i]<nums[j-1],这意味着i太小，增大i
2. i>imin且nums1[i-1]>nums[j],这意味着i太大，减小i
3. j=0 or i=m or nums2[j-1]<= nums1[i] 或者是 i=0 or j=n or nums1[i-1]<= nums2[j] 这是符合的。

	class Solution {
	public:
	    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	        int m=nums1.size(),n=nums2.size();
	         if (m > n)
	        {
	            auto tmp1 = nums1; nums1 = nums2; nums2 = tmp1;
	            unsigned int tmp2 = m; m = n; n = tmp2;
	        }
	        int iMin=0,iMax=m,half=(m+n+1)/2;
	        while(iMin<=iMax){
	            int i=(iMin+iMax)/2;
	            int j=half-i;
	            if(i<iMax && nums2[j-1]>nums1[i]) iMin = i+1;
	            else if(i>iMin &&nums1[i-1]>nums2[j]) iMax = i-1;
	            else{
	                int maxLeft = 0 ;
	                if(i==0) maxLeft = nums2[j-1];
	                else if(j==0) maxLeft = nums1[i-1];
	                else maxLeft = max(nums1[i-1],nums2[j-1]);
	                if(((m+n)%2)==1) return maxLeft;
	                
	                int minRight = 0;
	                if(i==m) minRight = nums2[j];
	                else if(j==n) minRight = nums1[i];
	                else minRight = min(nums1[i],nums2[j]);
	                return (maxLeft+minRight)/2.0;
	            }
	        }
	        return 0.0;
	    }
	};