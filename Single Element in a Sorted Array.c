class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(auto a:nums) res = res^a;
        return res;
    }
};