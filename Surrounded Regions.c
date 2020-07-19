class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;
        queue<int> q;
        for(int i=0;i<m;i++){
            board[i][0] = (board[i][0]=='O')?1:'X';
            if(board[i][0]==1) q.push(i*n);
            board[i][n-1] = (board[i][n-1]=='O')?1:'X';
            if(board[i][n-1]==1) q.push(i*n+n-1);
        }
        for(int i=0;i<n;i++){
            board[0][i] = (board[0][i]=='O')?1:'X';
            if(board[0][i]==1) q.push(i);
            board[m-1][i] = (board[m-1][i]=='O')?1:'X';
            if(board[m-1][i]==1) q.push((m-1)*n+i);
        }
        vector<pair<int,int>> indices = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            int x = tmp/n, y = tmp%n;
            board[x][y] = 2;
            for(auto ind:indices)
                if(x+ind.first>=0 && y+ind.second>=0 && x+ind.first<m && y+ind.second<n&&board[x+ind.first][y+ind.second]=='O'){
                    q.push((x+ind.first)*n+y+ind.second);
                    board[x+ind.first][y+ind.second] = 1;
                }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                if(board[i][j]==2) board[i][j] = 'O';
            }
    }
};