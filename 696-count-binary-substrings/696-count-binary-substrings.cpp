class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int sum =0, right=0, left=0, n = s.size();
        
        while(right < n)
        {
            char c = s[right];
            int count =0;
            while(right < n && s[right] == c)
            {
                right++;
                count++;
            }
            sum += min(count, left);
            left = count;
        }
        return sum;
    }
};