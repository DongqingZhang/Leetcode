class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()<1) return 0;
        int localMax = nums[0];
        int localMin = nums[0];
        int global = nums[0];
        for (int i = 1;i < nums.size();i++){
            int maxCopy = localMax;
            int minCopy = localMin;
            if (nums[i]<0){
                localMax = max(nums[i], minCopy*nums[i]);
                localMin = min(nums[i], maxCopy*nums[i]);
            }
            else{
                localMax = max(nums[i], maxCopy*nums[i]);
                localMin = min(minCopy*nums[i], nums[i]);
            }
            global = max(global, localMax);
        }
        return global;
    }
};