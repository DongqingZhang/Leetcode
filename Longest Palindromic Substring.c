class Solution {
public:
    string longestPalindrome(string s) {
    if (s.length() < 2) return s;
    int maxLen = 1;
    int start = 0;
    int end = 0;
    for (int i = 0;i < s.length();i++){
        int j = i;
        int k = i;
        if (2*(s.length() - i)-1 <= maxLen) break;
        while (k < s.length()-1 && s[k+1] == s[k]) k++;
        i = k;
        while(j >= 0 && k < s.length() && s[k] == s[j]){k++;j--;}
        if (maxLen < k - j - 1){
            maxLen = k - j - 1;
            start = j+1;
            end = k-1;
        }
    }
    return s.substr(start, maxLen);
    }
};
