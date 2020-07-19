class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.length();
        int half = len/2;
        for(int i = 0;i<half;i++){
            if(s[i] != s[len-1-i]) return isPalind(s,i+1,len-1-i) || isPalind(s,i,len-2-i);
        }
        return true;
    }
    bool isPalind(string s, int start, int end){
        int a = start, b = end;
        while(a < b){
            if(s[a]!=s[b]) return false;
            a++;
            b--;
        }
        return true;
    }
};