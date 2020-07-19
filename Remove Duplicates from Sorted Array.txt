class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        if (nums.size()<2) return nums.size();
        for (int i = 1;i<nums.size();i++){
            if (nums[index] != nums[i]) nums[++index] = nums[i];
        }
        return index+1;
    }
};