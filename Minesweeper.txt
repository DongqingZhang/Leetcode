class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        helper(board, click);
        return board;
    }
    void helper(vector<vector<char>>& board, vector<int>& click){
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return;
        }
        if(board[click[0]][click[1]] == 'E') board[click[0]][click[1]] = 'B';
        int cnt = 0, sx = board.size(), sy = board[0].size();
        for(int i = max(0,click[0]-1);i<=min(sx-1,click[0]+1);i++){
            for(int j = max(0,click[1]-1);j<=min(sy-1,click[1]+1);j++){
                if(i == click[0] && j == click[1]) continue;
                if(board[i][j] == 'M' || board[i][j] == 'X') cnt++;
            }
        }
        if(cnt == 0){
            for(int i = max(0,click[0]-1);i<=min(sx-1,click[0]+1);i++){
                for(int j = max(0,click[1]-1);j<=min(sy-1,click[1]+1);j++){
                    if(i == click[0] && j == click[1]) continue;
                    if(board[i][j] == 'E'){
                        vector<int> tmp = {i,j};
                        helper(board, tmp);
                    }
                }
            }
        }
        if(cnt) board[click[0]][click[1]] = cnt+'0';
        return;        
    }
};