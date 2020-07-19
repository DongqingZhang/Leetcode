class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> myMap;
        for (int i=0;i<s.length();i++) myMap[s[i]]++;
        int count = 0;
        for(auto a:myMap){
            if (a.second%2) count++;
        }
        if (count>1) return false;
        return true;
    }
};