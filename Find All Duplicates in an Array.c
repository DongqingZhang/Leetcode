class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(int i = 0;i<len;i++){
            int tmp = abs(nums[i])-1;
            if(nums[tmp] < 0) res.push_back(tmp+1);
            else nums[tmp] = -nums[tmp];
        }
        return res;
    }
};