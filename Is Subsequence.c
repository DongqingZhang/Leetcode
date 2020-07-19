class Solution {
public:
    bool isSubsequence(string s, string t) {
        int inds = 0,indt = 0, lens = s.length(),lent = t.length();
        while(inds < lens && indt < lent){
            if(t[indt]==s[inds]) inds++;
            indt++;
        }
        return inds==lens;
    }
};