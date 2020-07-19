class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 1) return res;
        helper(nums, 0, nums.size() - 1, res);
        return res;
    }
    void helper(vector<int>& nums, int l, int r, vector<vector<int>>& res){
        if (l == r){
            res.push_back(nums);
            return;
        }
        for (int i = l; i <= r;i++){
            swap(nums, l, i);
            helper(nums, l+1, r, res);
            swap(nums, l, i);
        }
    }
    void swap(vector<int>& nums, int l, int r){
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
};