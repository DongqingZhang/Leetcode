class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDist = nums[0];
        for (int i = 0;i<nums.size();i++){
            if (i <= maxDist) maxDist = max(maxDist, i+nums[i]);
        }
        if (maxDist < nums.size()-1) return false;
        return true;
    }
};