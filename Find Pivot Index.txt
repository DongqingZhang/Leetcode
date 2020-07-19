class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        long suml = 0, sum = 0;
        for(auto a:nums) sum += a;
        for(int i = 0;i < nums.size();i++){
            suml+=nums[i];
            if(suml*2 == sum+nums[i]) return i;
        }
        return -1;
    }
};