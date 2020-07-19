class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        vector<int> res(nums.size()+1,0);
        for (int i=1;i<nums.size()+1;i++)
            res[i] = res[i-1] + nums[i-1];
        int minNum = res[0];
        int maxDiff = nums[0];
        for (int i = 1;i < res.size();i++){
            if (maxDiff < res[i] - minNum)
                maxDiff = res[i] - minNum;
            if (minNum > res[i])
                minNum = res[i];
        }
        return maxDiff;
    }
};