class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        helper(nums, res, 0, nums.size());
        return res;
    }
    void helper(vector<int> s, vector<vector<int>>& res, int i, int j){
        if(i==j-1){
            res.push_back(s);
            return;
        }
        for(int k=i;k<j;k++){
            if(k!=i && s[k]==s[i]) continue;
            swap(s[k],s[i]);
            helper(s, res, i+1,j);
        }
    }
};