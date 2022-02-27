class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        int size = nums.size();
        int left=0, right= size-1;
        int result=0;
        vector<int>temp(size);
        mergesort(nums,temp, left, right, result);
        return result;
    }
    
    void mergesort(vector<int>& nums, vector<int>& temp, int left, int right, int& result)
    {
        if(left >= right) return;
        int mid = left +(right-left)/2;
        mergesort(nums, temp, left, mid, result);
        mergesort(nums, temp, mid+1, right, result);
        
        int i = left,  j = mid+1;
        while(i <= mid && j <= right)
        {
            if((long long)nums[i] > (long long)2*nums[j])
            {
                result += (mid-i+1);
                j++;
            }
            else
            {
                i++;
            }
        }
        
        i=left, j=mid+1;
        int t=0;
        while(i<=mid && j <= right)
        {
            if(nums[i] > nums[j])
            {
                temp[t++] = nums[j++];
            }
            else
            {
                temp[t++] = nums[i++];
            }
        }
        
        while(i <= mid)
        {
            temp[t++] = nums[i++];
        }
        while(j <= right)
        {
            temp[t++] = nums[j++];
        }
        t = 0;
        while(left <= right)
        {
            nums[left++] = temp[t++];
        }
    }
};