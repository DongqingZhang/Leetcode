class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        vector<vector<string>> res;
        for (auto s:strs){
            string tmp(s);
            sort(tmp.begin(),tmp.end());
            h[tmp].push_back(s);
        }
        for (auto kv:h){
            res.push_back(kv.second);
        }
        return res;
    }
};
