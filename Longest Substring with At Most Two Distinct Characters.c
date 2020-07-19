class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> map;
        int maxLen = 0, start = 0, len = s.length();
        for(int end = 0;end < len;end++){
            map[s[end]]++;
            while(map.size()>2){
                if(map[s[start]]>=2) map[s[start]]--;
                else map.erase(s[start]);
                start++;
            }
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};