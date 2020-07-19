class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<vector<int>>> set;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(grid[i][j] <= 0) continue;
                vector<vector<int>> indices;
                dfs(i,j,i,j,m,n,indices,grid);
                set.insert(indices);
            }
        return set.size();
    }
    bool dfs(int i0, int j0, int i, int j, int m, int n, vector<vector<int>>& indices, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]<=0) return false;
        grid[i][j] *= -1;
        indices.push_back({i-i0,j-j0});
        dfs(i0,j0,i+1,j,m,n,indices, grid);
        dfs(i0,j0,i-1,j,m,n,indices, grid);
        dfs(i0,j0,i,j+1,m,n,indices, grid);
        dfs(i0,j0,i,j-1,m,n,indices, grid);
        return true;
    }
};