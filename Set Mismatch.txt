class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup, sum = 0, len = nums.size();
        for(auto a:nums){
            sum += abs(a);
            if(nums[abs(a)-1] < 0) dup = abs(a);
            else nums[abs(a)-1] *= -1;
        }
        int diff = (len+1)*len/2 - sum;
        return {dup, dup+diff};
    }
};