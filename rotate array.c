class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverseArray(nums, 0, n - k - 1);
        reverseArray(nums, n - k, n - 1);
        reverseArray(nums, 0, n - 1);
    }
    void reverseArray(vector<int>& nums, int l, int r){
        if (l >= r) return;
        if (l < 0||r >= nums.size()) return;
        int tmp;
        for (int i = l;i <= l+(r-l)/2;i++){
            tmp = nums[i];
            nums[i] = nums[l+r-i];
            nums[l+r-i] = tmp;
        }
    }
};