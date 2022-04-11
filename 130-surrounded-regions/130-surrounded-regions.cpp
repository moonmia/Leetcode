class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j] == 'X'||board[i][j] == 'N'){
            return;
        }
        int di[4] ={1,-1,0,0};
        int dj[4] ={0,0,-1,1};
        board[i][j] ='N';
        
        for(int index=0; index<4; index++){
            int newDi = i+di[index];
            int newDj = j+dj[index];
            dfs(board, newDi, newDj);
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            dfs(board, i, 0);
            dfs(board, i, board[0].size()-1);
        }
        for(int j=0; j<board[0].size(); j++){
            dfs(board, 0, j);
            dfs(board, board.size()-1, j);
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j]='X';
                }
                
                if(board[i][j] == 'N'){
                    board[i][j]='O';
                }
            }
        }
    }
};