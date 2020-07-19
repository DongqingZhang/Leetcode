class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        for(int i = 0;i<n;i++)
            for(int j = i+1;j<n;j++) if(board[i][i]^board[i][j] != board[j][i]^board[j][j]) return -1;
        for(int i = 0;i<n;i++){
            rowSum+=board[0][i];
            colSum+=board[i][0];
            colSwap+=(board[0][i]==(i%2)?1:0);
            rowSwap+=(board[i][0]==(i%2)?1:0);
        }
        if(n%2 == 0) if(rowSum != n/2 || colSum != n/2) return -1;
        if(n%2) if((rowSum != n/2&&rowSum != n/2+1) || (colSum != n/2&&colSum != n/2+1)) return -1;
        if(n%2==0){
            colSwap = min(colSwap, n- colSwap);
            rowSwap = min(rowSwap, n- rowSwap);
        }
        else{
            if(colSwap%2) colSwap = n-colSwap;
            if(rowSwap%2) rowSwap = n-rowSwap;
        }
        return colSwap/2+rowSwap/2;
    }
};