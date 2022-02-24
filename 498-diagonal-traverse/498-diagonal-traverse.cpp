class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        vector<int>nums;
        int m = mat.size();
        int n = mat[0].size();
        if(m == 0 || n == 0) return nums;
        
        bool xflag = true;
        for(int i=0; i<m+n; i++)
        {
            int pm = xflag ? m : n;
            int pn = xflag ? n : m;
            
            int x = (i<pm) ? i : pm-1;
            int y = i-x;
            
            while(x >= 0 && y < pn)
            {
                nums.push_back(xflag ? mat[x][y] : mat[y][x]);
                x--;
                y++;
            }
            xflag = !xflag;
        }
        return nums;
    }
};