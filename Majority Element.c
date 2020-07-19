class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ret = 0;
        for (auto num:nums){
            if (count == 0) ret = num;
            if (ret == num) count++;
            else count--;
        }
        return ret;
    }
};