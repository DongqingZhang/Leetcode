class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxv = INT_MIN,maxs = INT_MIN, ind = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > maxv){
                maxv = nums[i];
                ind = i;
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > maxs && nums[i]!=maxv) maxs = nums[i];
        }
        if(maxv/2>=maxs) return ind;
        return -1;
    }
};