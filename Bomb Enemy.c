class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int rowhits, colhits[n], result = 0;
        for (int i = 0;i<m;i++)
            for (int j = 0;j<n;j++){
                if(j == 0||grid[i][j-1] == 'W'){
                    rowhits = 0;
                    for (int k = j;k<n&&grid[i][k]!='W';k++) rowhits+=(grid[i][k] == 'E');
                }
                if(i == 0||grid[i-1][j] == 'W'){
                    colhits[j] = 0;
                    for (int k = i;k<m&&grid[k][j]!='W';k++) colhits[j]+=(grid[k][j] == 'E');
                }
                if (grid[i][j] == '0') result = max(result,colhits[j]+rowhits);
            }
        return result;
    }
};