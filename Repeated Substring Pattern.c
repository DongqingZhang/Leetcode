class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.length();
        for(int i = 1;i < len/2+1;i++){
            if(str[i] == str[0]){
                if(len%i == 0){
                    int j;
                    for(j = i;j < len;j++){
                        if(str[j] != str[j%i]) break;
                    }
                    if(j == len) return true;
                }
            }
        }
        return false;
    }
};