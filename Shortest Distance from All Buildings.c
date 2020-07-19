class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return -1;
        int n = grid[0].size();
        if(n == 0) return -1;
        vector<vector<int>> distance(m, vector<int>(n,0));
        vector<vector<int>> times(m, vector<int>(n,0));
        int v = 1;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] != 1) continue;
                v--;
                queue<pair<int,int>> q;
                q.push({i,j});
                int dist = 0;
                while(!q.empty()){
                    int sz = q.size();
                    for(int k = 0;k < sz;k++){
                        pair<int,int> a = q.front();
                        q.pop();
                        distance[a.first][a.second]+=dist;
                        if(a.first-1 >= 0 && grid[a.first-1][a.second] == v){
                            q.push({a.first-1,a.second});
                            grid[a.first-1][a.second]--;
                        }
                        if(a.first+1 < m && grid[a.first+1][a.second] == v){
                            q.push({a.first+1,a.second});
                            grid[a.first+1][a.second]--;
                        }
                        if(a.second-1 >= 0 && grid[a.first][a.second-1] == v){
                            q.push({a.first,a.second-1});
                            grid[a.first][a.second-1]--;
                        }
                        if(a.second+1 < n && grid[a.first][a.second+1] == v){
                            q.push({a.first,a.second+1});
                            grid[a.first][a.second+1]--;
                        }
                    }
                    dist++;
                }
            }
        v--;
        int res = INT_MAX;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] == v && res > distance[i][j]) res = distance[i][j];
            }
        return res == INT_MAX?-1:res;
    }
};