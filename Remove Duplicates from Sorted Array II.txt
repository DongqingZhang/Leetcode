class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        if (nums.size()<3) return nums.size();
        for (int i = 1;i < nums.size();i++){
            if (index<1 || nums[i] > nums[index-1]) nums[++index] = nums[i];
        }
        return index+1;
    }
};