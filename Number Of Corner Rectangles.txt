class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<i;j++){
                int cnt = 0;
                for(int k = 0;k<n;k++){
                    if(grid[i][k] && grid[j][k]) cnt++;
                }
                res += cnt*(cnt-1)/2;
            }
        }
        return res;
    }
};