class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxv = INT_MIN, minv = INT_MAX, beg = -1,end = -2, len = nums.size();
        for(int i = 0;i < len;i++){
            maxv = max(maxv, nums[i]);
            minv = min(minv, nums[len-1-i]);
            if(nums[i] < maxv) end = i;
            if(nums[len-1-i] > minv) beg = len-1-i;
        }
        return end-beg+1;
    }
};