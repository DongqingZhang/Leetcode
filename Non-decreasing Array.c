class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MAX);
        int cnt = 0;
        for(int i = 2;i<=len;i++){
            if(nums[i] < nums[i-1]){
                cnt++;
                if(nums[i-2]>nums[i]) nums[i] = nums[i-1];
                else nums[i-1] = nums[i];
            }
        }
        return cnt<2;
    }
};