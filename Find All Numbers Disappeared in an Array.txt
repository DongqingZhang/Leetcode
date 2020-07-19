class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for(int i = 0;i<len;i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for(int i = 0;i<len;i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};