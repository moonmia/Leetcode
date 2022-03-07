class Solution {
public:
    int minSwaps(string s) 
    {
        int ans=0, right=0, left=0;
        
        for(char ch : s)
        {
            if(ch == '[') left++;
            else right++;
            
            if(right > left)
            {
                ans ++;
                left++;
                right--;
            }
        }
        return ans;
    }
};