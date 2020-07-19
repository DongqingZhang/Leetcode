class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = 1;i<s.length();i++){
            if (s[i] == '+'&&s[i-1] == '+'){
                res.push_back(s);
                res[res.size()-1][i] = '-';
                res[res.size()-1][i-1] = '-';
            }
        }
        return res;
    }
};