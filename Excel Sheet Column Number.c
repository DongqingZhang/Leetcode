class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0;i<s.length();i++){
            res += (s[s.length()-i-1] - 64)*pow(26,i);
        }
        return res;
    }
};