class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int left=0, right=arr.size();
        
        while(left <right)
        {
            int mid = left + (right-left)/2;
            
            if(arr[mid]-mid >= k+1)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left+k;
    }
};