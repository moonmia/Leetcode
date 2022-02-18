class Solution {
public:
    int numTeams(vector<int>& rating) 
    {
        int n=rating.size(), count=0;
        for(int j=1; j<n-1; j++)
        {
            int i_less=0, i_more=0;
            int k_less=0, k_more=0;
            for(int i=0; i<j; i++)
            {
                if(rating[i] < rating[j])
                {
                    i_less++;
                }
                else
                {
                    i_more++;
                }
            }
            for(int k=j+1; k<n; k++)
            {
                if(rating[k] < rating[j])
                {
                    k_less++;
                }
                else
                {
                    k_more++;
                }
            }
            count += i_less*k_more + i_more*k_less;
        }
        return count;
    }
};