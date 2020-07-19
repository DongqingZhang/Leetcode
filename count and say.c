class Solution {
public:
    string countAndSay(int n) {
        return helper(n);
    }
    string helper(int n){
        string res;
        if (n == 1){
            res.push_back('1');
            return res;
        }
        string s = helper(n-1);
        char cur = s[0];
        int count = 1;
        for (int i = 1;i<s.length();i++){
            if (s[i] != cur){
                res.push_back('0'+count);
                res.push_back(cur);
                count = 1;
                cur = s[i];
            }
            else
                count++;
        }
        res.push_back(count+'0');
        res.push_back(cur);
        return res;
    }
};