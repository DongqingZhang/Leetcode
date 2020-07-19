class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if(len <= 1) return true;
        if(word[0] <= 'Z'){
            if(word[1] <= 'Z'){
                for(int i = 2;i<len;i++){
                    if(word[i] >= 'a') return false;
                }
                return true;
            }
            for(int i = 1;i<len;i++){
                if(word[i] <= 'Z') return false;
            }
        }
        if(word[0] >= 'a'){
            for(int i = 1;i<len;i++){
                if(word[i] <= 'Z') return false;
            }
        }
        return true;
    }
};