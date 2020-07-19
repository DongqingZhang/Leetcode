class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size()<10) return {};
        int len = s.size();
        vector<string> res;
        unordered_map<int, int> myMap;
        long t = 0;
        for (int i = 0;i < 10;i++)
            t = (t<<3 | (s[i]&7));
        for (int i = 0;i<len - 9;i++){
            if (myMap[t] == 1) res.push_back(s.substr(i,10));
            myMap[t]++;
            t = ((t<<3 & 0x3fffffff)|(s[i+10]&7));
        }
        return res;
    }
};