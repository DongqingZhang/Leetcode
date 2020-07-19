class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for(int i = 0;i<=len/k/2;i++){
            helper(s, i*2*k, min(i*2*k+k-1,len-1));
        }
        return s;
    }
    void helper(string& str, int s, int e){
        if(s>=e) return;
        while(e > s){
            char tmp = str[s];
            str[s] = str[e];
            str[e] = tmp;
            s++;
            e--;
        }
    }
};