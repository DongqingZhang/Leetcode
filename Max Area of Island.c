class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int resmax = 0, tmp = 0;
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++){
                dfs(grid,i,j,tmp);
                resmax = max(tmp,resmax);
                tmp = 0;
            }
        return resmax;
    }
    void dfs(vector<vector<int>>& grid, int r, int c, int& res){
        if(r>=grid.size() || r<0 || c>=grid[0].size() || c<0 || grid[r][c] != 1) return;
        res++;
        grid[r][c] = 0;
        dfs(grid,r+1,c,res);
        dfs(grid,r-1,c,res);
        dfs(grid,r,c+1,res);
        dfs(grid,r,c-1,res);
    }
};