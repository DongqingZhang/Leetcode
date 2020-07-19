class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    bool helper(vector<vector<char>>& board){
        for(int i = 0;i<9;i++)
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    for(int k = 1;k<10;k++){
                        if (isValid(board,i,j,k)){
                            board[i][j] = k+48;
                            if (helper(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int i, int j, int val){
        for (int k = 0;k<9;k++){
            if (board[i][k] == val+48) return false;
        }
        for (int k = 0;k<9;k++){
            if (board[k][j] == val+48) return false;
        }
        for (int ii = i - i%3;ii<i - i%3 + 3;ii++)
            for (int jj = j - j%3;jj<j - j%3 + 3;jj++){
                if (board[ii][jj] == val+48) return false;
        }
        return true;
    }
};