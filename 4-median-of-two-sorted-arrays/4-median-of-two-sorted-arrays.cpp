class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size(), n= nums2.size();
        int left = (m+n+1)/2;
        int right = (m+n+2)/2;
        return (findKth(nums1,0,nums2,0,left) + findKth(nums1,0,nums2,0,right)) / 2.0;
    }
    
    int findKth(vector<int>&nums1, int i, vector<int>&nums2, int j, int k)
    {
        int m = nums1.size(), n= nums2.size();
        if(i >= m) return nums2[j+k-1];
        if(j >= n) return nums1[i+k-1];
        if(k == 1) return min(nums1[i], nums2[j]);
        
        int midVal1 = (i+k/2 -1 < m) ? nums1[i+k/2 -1] : INT_MAX;
        int midVal2 = (j+k/2 -1 < n) ? nums2[j+k/2 -1] : INT_MAX;
        
        if(midVal1 < midVal2)
        {
            return findKth(nums1, i+k/2, nums2, j, k-k/2);
        }
        else
        {
            return findKth(nums1, i, nums2, j+k/2, k-k/2);
        }
    }
};