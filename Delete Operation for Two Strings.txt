class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> res(m+1,vector<int>(n+1,0));
        for(int i = 0;i<=m;i++)
            for(int j = 0;j<=n;j++){
                if(i == 0 || j == 0) res[i][j] = 0;
                else res[i][j] = (word1[i-1] == word2[j-1]?res[i-1][j-1]+1:max(res[i-1][j],res[i][j-1]));
            }
        return m+n-2*res[m][n];
    }
};