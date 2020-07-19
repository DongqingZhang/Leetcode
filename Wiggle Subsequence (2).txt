class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> diff;
        if (nums.size()<2) return nums.size();
        for (int i = 1;i<nums.size();i++){
            if (nums[i]!=nums[i-1]) diff.push_back(nums[i]-nums[i-1]);
        }
        if (diff.size() == 0) return 1;
        int count = 1;
        for (int i = 1;i<diff.size();i++){
            if(diff[i]*diff[i-1]<0) count++;
        }
        count++;
        return count;
    }
};