class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m+1, vector<int>(n+1,0));
        for(auto a:strs){
            int numones = 0, numzeros = 0;
            for(auto s:a){
                if(s == '0') numzeros++;
                else numones++;
            }
            for(int i = m;i>=numzeros;i--)
                for(int j = n;j>=numones;j--){
                    memo[i][j] = max(memo[i][j],memo[i-numzeros][j-numones]+1);
                }
        }
        return memo[m][n];
    }
};