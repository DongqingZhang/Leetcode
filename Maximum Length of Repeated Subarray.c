class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        if(m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int res = 0;
        for(int i = 1;i<=m;i++)
            for(int j = 1;j<=n;j++) res = max(res, dp[i][j] = A[i-1]==B[j-1]?1+dp[i-1][j-1]:0);
        return res;
    }
};