class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(128,0);
        unordered_map<char, int> map;
        if(s1.length() == 0) return true;
        for(int i = 0;i < s1.length();i++) cnt[s1[i]]--;
        for(int l = 0, r = 0;r<s2.length();r++){
            if(++cnt[s2[r]] > 0) while(--cnt[s2[l++]]!=0);
            else if(r-l+1 == s1.length()) return true;
        }
        return false;
    }
};