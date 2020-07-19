class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n--){
            res = (char)(n%26+1+64) + res;
            n /= 26;
        }
        return res;
    }
};