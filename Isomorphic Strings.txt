class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_map<char,char>::const_iterator got;
        for (int i = 0;i<s.size();i++){
            got = map.find(s[i]);
            if (got == map.end()) map[s[i]] = t[i];
            else if (got->second != t[i]) return false;
        }
        map.clear();
        for (int i = 0;i<t.size();i++){
            got = map.find(t[i]);
            if (got == map.end()) map[t[i]] = s[i];
            else if (got->second != s[i]) return false;
        }
        return true;
    }
};