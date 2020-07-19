class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int f = 0,s = 0;
        while(f<nums.size()){
            if(nums[f] == 0) f++;
            else{
                nums[s] = nums[f];
                s++;
                f++;
            }
        }
        for(int i = s;i<nums.size();i++) nums[i] = 0;
    }
};