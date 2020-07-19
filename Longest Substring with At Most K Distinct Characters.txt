class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int maxLen = 0, start = 0, len = s.length();
        for(int end = 0;end < len;end++){
            map[s[end]]++;
            while(map.size()>k){
                if(map[s[start]]>=2) map[s[start]]--;
                else map.erase(s[start]);
                start++;
            }
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};