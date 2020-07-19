class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i = 31;i>=0;i--){
            unordered_set<int> set;
            mask |= (1<<i);
            for(auto a:nums) set.emplace(a & mask);
            int tmp = res | (1<<i);
            for(auto a:set){
                if(set.count(tmp ^ a)){
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};