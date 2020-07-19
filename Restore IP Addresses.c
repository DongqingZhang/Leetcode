class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() <= 3||s.length()>12) return res;
        int len = s.length();
        for (int j = 1;j<len - 2;j++)
            for (int k = j+1;k<len - 1;k++)
                for (int l = k+1;l<len;l++){
                    if (isValid(s.substr(0,j))&&isValid(s.substr(j,k-j))&&isValid(s.substr(k,l-k))&&isValid(s.substr(l,len-l)))
                        res.push_back(s.substr(0,j)+'.'+s.substr(j,k-j)+'.'+s.substr(k,l-k)+'.'+s.substr(l,len-l));
                }
        return res;
    }
    bool isValid(string s){
        if (s.length()>3||stoi(s)>255||(s.size() != 1&&s[0] == '0')) return false;
        return true;
    }
};