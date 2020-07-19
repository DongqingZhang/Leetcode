class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        int len = 0;
        for(auto a:d){
            if (isSub(s, a)){
                int lent = a.length();
                if(len<lent){
                    res = a;
                    len = lent;
                }
                if(len == lent && lex(res, a)) res = a;
            }
        }
        return res;
    }
    bool isSub(string s, string d){
        if(d.length() > s.length()) return false;
        int ind = 0;
        for(int i = 0;i < d.length();i++){
            while(ind < s.length() && s[ind] != d[i]) ind++;
            if(ind == s.length()) return false;
            if(s[ind] == d[i]) ind++;
        }
        return true;
    }
    bool lex(string s, string t){
        int i = 0;
        while(i < s.length() && s[i] == t[i]) i++;
        if(i == s.length()) return true;
        return s[i]>t[i];
    }
};