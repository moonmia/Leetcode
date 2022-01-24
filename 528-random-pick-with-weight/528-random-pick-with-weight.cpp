class Solution {
public:
    int sum=0;
    vector<int>prefix;
    Solution(vector<int>& w) 
    {
        
        for(auto & W : w)
        {
            sum += W;
            prefix.push_back(sum);
        }
    }
    
    int pickIndex() 
    {
        int random = rand()%sum;
        
        int left =0, right = prefix.size()-1;
        
        while(left < right)
        {
            int mid = left + (right-left)/2;
            
            if(random >= prefix[mid])
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
            
        }
        return left;
    }
};




/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */