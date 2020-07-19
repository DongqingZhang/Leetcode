class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.size() == 0 || M[0].size() == 0) return 0;
        int res = 0, m = M.size(), n = M[0].size(), hori = 0, vert = 0, diag = 0, antid = 0;
        for(int i = 0;i < m;i++){
            hori = 0;
            for(int j = 0;j < n;j++){
                hori = M[i][j]?hori+1:0;
                res = max(res, hori);
            }
        }
        for(int j = 0;j < n;j++){
            vert = 0;
            for(int i = 0;i < m;i++){
                vert = M[i][j]?vert+1:0;
                res = max(res, vert);
            }
        }
        for(int j = 0;j < m+n-1;j++){
            diag = 0;
            for(int i = max(0,j-n+1);i <= min(j,m-1);i++){
                diag = M[i][j-i]?diag+1:0;
                res = max(res, diag);
            }
        }
        for(int j = 0;j < m+n-1;j++){
            antid = 0;
            for(int i = max(0,j-n+1);i <= min(j,m-1);i++){
                antid = M[i][i+n-1-j]?antid+1:0;
                res = max(res, antid);
            }
        }
        return res;
    }
};