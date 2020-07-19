class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        int cnt = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,i,j);
                }
            }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';
        if(x>0&&grid[x-1][y]=='1') dfs(grid,x-1,y);
        if(x<grid.size()-1&&grid[x+1][y]=='1') dfs(grid,x+1,y);
        if(y>0&&grid[x][y-1]=='1') dfs(grid,x,y-1);
        if(y<grid[0].size()-1&&grid[x][y+1]=='1') dfs(grid,x,y+1);
    }
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<int> q;
        q.push(i*grid[0].size()+j);
        while(!q.empty()){
            int tmp = q.front();
            int x = tmp/grid[0].size(), y = tmp%grid[0].size();
            q.pop();
            if(x>0&&grid[x-1][y]=='1'){grid[x-1][y]='0'; q.push((x-1)*grid[0].size()+y);}
            if(x<grid.size()-1&&grid[x+1][y]=='1'){grid[x+1][y]='0'; q.push((x+1)*grid[0].size()+y);};
            if(y>0&&grid[x][y-1]=='1'){grid[x][y-1]='0'; q.push(x*grid[0].size()+y-1);};
            if(y<grid[0].size()-1&&grid[x][y+1]=='1'){grid[x][y+1]='0'; q.push(x*grid[0].size()+y+1);};
        }
    }
};