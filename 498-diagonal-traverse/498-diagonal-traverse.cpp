class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        vector<int>ans;
        int row = mat.size(), col=mat[0].size();
        int sum = row*col;
        int x=0, y=0;
        
        for(int i=0; i<sum; i++)
        {
            ans.push_back(mat[x][y]);
            
            if((x+y)%2 == 0)
            {
                if(y == col-1) x++;
                else if (x ==0) y++;
                else x--, y++;
            }
            else
            {
                if(x == row-1) y++;
                else if(y==0) x++;
                else x++, y--;
            }
        }
        return ans;
    }
};