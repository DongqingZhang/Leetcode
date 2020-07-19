class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.length() == 0) return "";
        vector<int> cnt(26,0);
        int pos = 0;
        for(int i = 0;i<s.length();i++) cnt[s[i]-'a']++;
        for(int i = 0;i<s.length();i++){
            if(s[i] < s[pos]) pos = i;
            if(--cnt[s[i]-'a'] == 0) break;
        }
        string s1;
        for(int i = pos;i<s.length();i++){
            if(s[i] != s[pos]) s1.push_back(s[i]);
        }
        return s[pos]+removeDuplicateLetters(s1);
    }
};