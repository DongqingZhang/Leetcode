class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, len = s.length(), start = 0, maxCnt = 0;
        vector<int> cnt(26,0);
        for(int i = 0;i<len;i++){
            maxCnt = max(maxCnt, ++cnt[s[i]-'A']);
            if(i-start+1-maxCnt > k){
                cnt[s[start++]-'A']--;
            }
            maxLen = max(maxLen, i - start+1);
        }
        return maxLen;
    }
};