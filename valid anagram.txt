class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() == 0&& t.size() == 0) return true;
        if (s.size() != t.size()) return false;
        string ss(s);
        sort(ss.begin(),ss.end());
        string ts(t);
        sort(ts.begin(),ts.end());
        for (int i = 0;i < s.size(); i++)
            if (ts[i]!=ss[i]) return false;
        return true;
    }
};