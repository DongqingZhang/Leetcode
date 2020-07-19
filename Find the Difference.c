class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        for(auto a:s) map[a]++;
        for(auto a:t){
            if(map[a]==0) return a;
            else map[a]--;
        }
    }
};