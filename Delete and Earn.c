class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10000,0);
        int take = 0, skip = 0;
        for(auto a:nums) v[a]+=a;
        for(int i = 0;i < 10000;i++){
            int takei = skip + v[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};