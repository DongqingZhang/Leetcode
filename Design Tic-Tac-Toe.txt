class TicTacToe {
public:
    /** Initialize your data structure here. */
    int len=0, winner=0, diag=0, antiDiag=0;
    vector<int> rows, cols;
    TicTacToe(int n) {
        len = n;
        for (int i=0;i<n;i++){
            rows.push_back(0);
            cols.push_back(0);
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (winner) return winner;
        int toAdd = player == 1?1:-1;
        rows[row]+=toAdd;
        cols[col]+=toAdd;
        if (col+row==len-1) antiDiag+=toAdd;
        if (col==row) diag+=toAdd;
        if (abs(rows[row])==len||abs(cols[col])==len||abs(diag)==len||abs(antiDiag)==len){winner = player;return player;}
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */