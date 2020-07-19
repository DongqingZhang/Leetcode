class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> col(m,0);
        vector<int> row(n,0);
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(grid[i][j] > col[i]) col[i] = grid[i][j];
                if(grid[i][j] > row[j]) row[j] = grid[i][j];
            }
        int res = 0;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++){
                res+=(min(col[i],row[j])-grid[i][j]);
            }
        return res;
    }
};