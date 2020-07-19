class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length()==t.length()){
            int cnt=0;
            for (int i=0;i<s.length();i++){
                if (s[i]!=t[i]) cnt++;
            }
            return (cnt==1);
        }
        if (s.length()==t.length()+1) return isOneDelete(s,t);
        if (s.length()==t.length()-1) return isOneDelete(t,s);
        return false;
    }
    bool isOneDelete(string s, string t){
        int cnt=0;
        int i;
        for (i=0;i<t.length();i++){
            if (s[i]!=t[i]) break;
        }
        if (i==t.length()) return true;
        else{
            for (int j=i;j<t.length();j++){
                if (s[j+1]!=t[j]) return false;
            }
            return true;
        }
    }
};