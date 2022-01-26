class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int size = m+n-1;
        m--;
        n--;
        
        while(n>=0)
        {
            while(m>=0 && nums1[m] > nums2[n])
            {
                swap(nums1[m--], nums1[size--]);
            }
            swap(nums1[size--], nums2[n--]);
        }
    }
};