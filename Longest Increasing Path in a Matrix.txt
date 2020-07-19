class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m<1)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int temp = 0;
        for (int i = 0;i<m; i++)
            for(int j = 0; j<n;j++){
                temp = max(temp,dfs(i,j,m,n,matrix, dp));
            }
        return temp;
    }
private:
    int dfs(int x, int y, int m, int n, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if (dp[x][y])   return dp[x][y];
        dp[x][y] = 1;
        for (int i=x-1;i<x+2;i++)
            for (int j=y-1;j<y+2;j++){
                if ((i>=0)&&(j>=0)&&(i<m)&&(j<n)&&matrix[i][j] > matrix[x][y]&&(i==x||j==y)){
                    dp[x][y] = max(dfs(i,j,m,n,matrix,dp) + 1, dp[x][y]);
                }
            }
        return dp[x][y];
    }
};