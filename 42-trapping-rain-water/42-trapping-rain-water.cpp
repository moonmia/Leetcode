class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.size() <=2) return 0;
        
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = height.size();
        
        maxLeft[0] = height[0];
        
        for(int i=1; i<size; i++)
        {
            maxLeft[i] = max(height[i], maxLeft[i-1]);
        }
        
        maxRight[size-1] = height[size-1];
        
        for(int i=size-2; i>=0; i--)
        {
            maxRight[i] = max(height[i], maxRight[i+1]);
        }
        
        int sum=0;
        
        for(int i=0; i<size; i++)
        {
            int count = min(maxLeft[i], maxRight[i])-height[i];
            if(count >0) sum += count;
        }
        return sum;
    }
};