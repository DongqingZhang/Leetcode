class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = -2;
        int len = s.length();
        for(int i = 0;i<len;i++){
            if(s[i] == ' '){
                start = end+2;
                end = i-1;
                reverse(s.begin()+start, s.begin()+end+1);
            }
        }
        reverse(s.begin()+end+2,s.begin()+len);
        return s;
    }
};