class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int di[4] = {0,0,-1,1};
        int dj[4] = {1,-1,0,0};
        int direction =0;
        int i =0, j= -1;
        int cnt = matrix[0].size() * matrix.size();
        vector<int>res;
        while (cnt >0){
            int newDi = i + di[direction%4];
            int newDj = j + dj[direction%4];
            if(newDi<0 || newDj<0 || newDi >= matrix.size() || newDj >= matrix[0].size() || matrix[newDi][newDj] == -10){
                direction++;
            }
            else{
                res.push_back(matrix[newDi][newDj]);
                matrix[newDi][newDj]=-10;
                i = newDi;
                j = newDj;
                cnt--;
                
            }
        }
        return res;
    }
};