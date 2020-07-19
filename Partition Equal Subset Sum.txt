class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        return backtrack(nums, 0, sum/2);
    }
    bool backtrack(vector<int>& nums, int start, int sum){
        if(sum <= 0) return sum == 0;
        for(int i = start;i<nums.size();i++){
            if(backtrack(nums, i+1,sum-nums[i])) return true;
        }
        return false;
    }
};