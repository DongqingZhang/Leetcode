class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, nums.size(), res);
        return res;
    }
    void helper(vector<int>& nums, int n, vector<vector<int>>& res){
        if (n == 0){
            res.push_back(vector<int>(0,0));
            return;
        }
        helper(nums, n - 1, res);
        int len = res.size();
        vector<int> tmp;
        for (int i = 0;i < len;i++){
            tmp = res[i];
            tmp.push_back(nums[n-1]);
            res.push_back(tmp);
        }
    }
};