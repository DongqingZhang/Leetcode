class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.length() < 2) return 0;
        int cur = 0, i = 0, res = 0;
        vector<int> g;
        while(i < s.length()){
            while(i < s.length() && s[i] == s[cur]) i++;
            g.push_back(i-cur);
            cur = i;
        }
        for(i = 1;i < g.size();i++) res += min(g[i-1],g[i]);
        return res;
    }
};