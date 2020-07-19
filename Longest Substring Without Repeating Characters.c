class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(300,0);
        int indl = 0;
        int maxL = 0;
        int curL = 0;
        for (int i = 0;i < s.size();i++){
            count[s[i]]++;
            curL++;
            if (count[s[i]] > 1){
                while(s[indl] != s[i]&&indl<i){
                    count[s[indl]]--;
                    indl++;
                    curL--;
                }
                count[s[indl]]--;
                indl++;
                curL--;
            }
            maxL = max(maxL, curL);
        }
        return maxL;
    }
};