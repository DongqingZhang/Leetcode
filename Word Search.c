class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if (isFound(board, word.c_str(), 1,i,j)) return true;
            }
        return false;
    }
    bool isFound(vector<vector<char>>& board, const char* word, int cnt, int x, int y){
        if (x<0||x>=m||y<0||y>=n||board[x][y]=='\0') return false;
        if (*(word+1) == '\0') return (board[x][y] == *word)&&board[x][y]!='\0';
        if (*word != board[x][y]) return false;
        char t = board[x][y];
        board[x][y] = '\0';
        bool res = isFound(board,word+1, cnt+1, x-1,y)
            ||isFound(board,word+1, cnt+1, x,y-1)
            ||isFound(board,word+1, cnt+1, x,y+1)
            ||isFound(board,word+1, cnt+1, x+1,y);
        board[x][y] = t;
        return res;
    }
private: int m, n;
};