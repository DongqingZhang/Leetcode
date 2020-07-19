class Solution {
public:
    int numDecodings(string s) {
        if (s.length()<1) return 0;
        vector<int> res(s.length()+1,1);
        if (s[0] == '0') {
            res[1] = 0;
            res[2] = 0;
        }
        else res[1] = 1;
        if (s.length() == 1) return res[1];
        for (int i = 2;i<res.size();i++){
            if ((s[i-2] == '0'||s[i-2]>='3')&&s[i-1] == '0') res[i] = 0;
            if ((s[i-2] == '1'||s[i-2] == '2')&&s[i-1] == '0') res[i] = res[i-2];
            if ((s[i-2] == '1'&&s[i-1]>'0')||(s[i-2] == '2'&&(s[i-1]>='1'&&s[i-1]<='6'))) res[i] = res[i-1]+res[i-2];
            if ((s[i-2] == '0'&&s[i-1]>'0')||(s[i-2]=='2'&&s[i-1]>='7')||(s[i-2]>'2'&&s[i-1] != '0')) res[i] = res[i-1];
            if (s[i-2]>='3'&&s[i-1]=='0') res[i] = 0;
        }
        return res[res.size()-1];
    }
};