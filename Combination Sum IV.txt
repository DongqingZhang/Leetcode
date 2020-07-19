class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> res(target+1,0);
        for (int i = 0;i<res.size();i++){
            for (auto num:nums){
                if (num > i) break;
                else if (num == i) res[i]++;
                else res[i]+=res[i-num];
            }
        }
        return res[target];
    }
};