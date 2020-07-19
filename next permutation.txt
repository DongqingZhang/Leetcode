class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int pos = nums.size() - 1;
        while(pos >= 1 && nums[pos] <= nums[pos - 1])
            pos--;
        if (pos == 0){
            sort(nums.begin(),nums.end());
            return;
        }
        int tmp = nums[pos];
        int ind = pos;
        for (int i = pos;i < nums.size();i++){
            if (nums[i] > nums[pos - 1]){
                tmp = min(tmp, nums[i]);
                if (tmp = nums[i])
                    ind = i;
            }
        }

        tmp = nums[ind];
        nums[ind] = nums[pos - 1];
        nums[pos - 1] = tmp;
        sort(nums.begin() + pos, nums.end());
        return;
    }
};