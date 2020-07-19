class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        helper(s, cur, res, 0);
        return res;
    }
    void helper(string s, vector<string>& cur, vector<vector<string>>& res, int start){
        int len = s.length();
        if (len == start){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<len;i++){
            if(!isP(s,start,i)) continue;
            cur.push_back(s.substr(start,i-start+1));
            helper(s, cur, res, i+1);
            cur.pop_back();
        }
    }
    bool isP(string s, int start, int end){
        while(end>start){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};