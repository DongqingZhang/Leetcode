class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for(auto c:s) map[c]++;
        int oddcnt = 0;
        int maxL = 0;
        for(auto a:map){
            maxL += (a.second - (a.second%2));
            if(oddcnt == 0 && a.second%2){
                oddcnt++;
                maxL++;
            }
        }
        return maxL;
    }
};