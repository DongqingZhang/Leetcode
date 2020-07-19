class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ind = 0, len = nums.size(), res = 0;
        long prod = 1;
        for(int i = 0;i < len;i++){
            prod *= nums[i];
            while(ind <= i && prod >= k) prod /= nums[ind++];
            res += (i-ind+1);
        }
        return res;
    }
};