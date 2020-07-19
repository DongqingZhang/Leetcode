class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int x1 = INT_MAX, x2 = INT_MAX;
        for (int i = 0;i < nums.size();i++){
            if (nums[i] > x2) return true;
            x1 = x1 < nums[i]?x1:nums[i];
            if (x2 > nums[i] && nums[i] > x1) x2 = nums[i];
        }
        return false;
    }
};