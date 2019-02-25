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