class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        for (int i = 0;i<=high;i++){
            while (nums[i] == 2&&i<high) swap(nums[i], nums[high--]);
            while (nums[i] == 0&&i>low) swap(nums[i], nums[low++]);
        }
    }
};