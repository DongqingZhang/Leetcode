class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.size() == 0) return res;
        for (int i = 0;i < strs[0].size();i++){
            for (int j = 0;j < strs.size();j++){
                if (strs[j].size() == i||strs[j][i] != strs[0][i])
                    return res;
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};