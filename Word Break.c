class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        if(len == 0) return true;
        vector<bool> dp(len+1,false);
        dp[0] = true;
        for(int i = 1;i <= len;i++){
            for(int j = i-1;j >=0;j--){
                if(dp[j] && wordDict.find(s.substr(j,i-j))!=wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};