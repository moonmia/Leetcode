class Solution {
public:
    int reverse(int x) 
    {
        int ans =0;
        while (x != 0)
        {
            int reminder = x % 10;
            x = x/10;
            if(ans >INT_MAX/10 || (ans == INT_MAX/10 && reminder >7 )) return 0;
            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && reminder < -8)) return 0;
            
            ans = ans *10 + reminder;
        }
        return ans;
    }
};