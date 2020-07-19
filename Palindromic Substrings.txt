class Solution {
public:
    int cnt = 0;
    int countSubstrings(string s) {
        for(int i = 0;i < s.length();i++){
            extendPal(s, i, i);
            extendPal(s, i, i+1);
        }
        return cnt;
    }
    void extendPal(string s, int l, int r){
        while(l >= 0 && r < s.length()){
            if(s[l--] == s[r++]) cnt++;
            else return;
        }
    }
};