class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> numsNew;
        numsNew.push_back(1);
        for (int i = 0;i < nums.size();i++){
            if (nums[i]) numsNew.push_back(nums[i]);
        }
        numsNew.push_back(1);
        int len = numsNew.size();
        vector<vector<int>> memo(len,vector<int>(len,0));
        return helper(memo, numsNew, 0, len - 1);
    }
    int helper(vector<vector<int>>& memo, vector<int>& nums, int left, int right){
        if (left+1 == right) return 0;
        if (memo[left][right] > 0) return memo[left][right];
        int res = 0;
        for(int i = left+1;i<right;i++){
            res = max(res, nums[left]*nums[i]*nums[right] + helper(memo, nums, left, i) + helper(memo, nums, i, right));
        }
        memo[left][right] = res;
        return res;
    }
};