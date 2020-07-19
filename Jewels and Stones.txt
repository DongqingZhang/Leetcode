class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> set;
        for(auto a:J) set.emplace(a);
        int res = 0;
        for(auto a:S) if(set.count(a)) res++;
        return res;
    }
};