class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows;
        vector<int> cols;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1) rows.push_back(i);
            }
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++){
                if(grid[j][i] == 1) cols.push_back(i);
            }
        int dist = 0;
        int x = rows[(rows.size()-1)/2];
        int y = cols[(cols.size()-1)/2];
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    dist += (abs(x - i) + abs(y - j));
                }
            }
        return dist;
    }
};