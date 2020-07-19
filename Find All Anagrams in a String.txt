class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lp = p.length(), ls = s.length(), start = 0, end = 0, cnt = p.length();
        vector<int> map(256,0);
        vector<int> res;
        for(int i = 0;i<lp;i++) map[p[i]]++;
        while(end<ls){
            if(map[s[end++]]-->=1) cnt--;
            if(cnt == 0) res.push_back(start);
            if(end-start == lp && map[s[start++]]++ >= 0) cnt++;
        }
        return res;
    }
};