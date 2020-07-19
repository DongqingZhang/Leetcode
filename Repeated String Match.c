class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int la = A.length(), lb = B.length();
        string res;
        int rep = lb/la;
        for(int i = 0;i<rep;i++) res.append(A);
        if(res.compare(B) == 0) return rep;
        res.append(A);
        if(isSubstring(res, B)) return rep+1;
        res.append(A);
        if(isSubstring(res, B)) return rep+2;
        return -1;
    }
    bool isSubstring(string res, string B){
        int pos = res.find(B);
        return pos!=string::npos;
    }
};