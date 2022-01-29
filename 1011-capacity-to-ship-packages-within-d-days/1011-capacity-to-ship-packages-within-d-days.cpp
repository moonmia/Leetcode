class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
       int left = *max_element(weights.begin(), weights.end());
       int right = accumulate(weights.begin(), weights.end(), 0);

       while(left < right)
       {
           int mid = (left+right)/2;
           int need_days =1, cur_weight =0;
           for(int weight : weights)
           {
               if(cur_weight + weight > mid)
               {
                   need_days++;
                   cur_weight=0;
               }
               cur_weight += weight;
           }
           if(need_days <= days)
           {
               right = mid;
           }
           else
           {
               left = mid+1;
           }
       }
       return left;
    }
};