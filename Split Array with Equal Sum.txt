class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int m = nums.size();
        if(m < 7) return false;
        vector<int> sums(m,nums[0]);
        for(int i = 0;i<m-1;i++) sums[i+1] = sums[i]+nums[i+1];
        for(int j = m-2;j>=5;j--)
            for(int i = 1;i<=j-4;i++){
                if(sums[m-1]-sums[j] != sums[i-1]) continue;
                int y = sums[m-1] - sums[i-1]*4-nums[i]-nums[j];
                for(int k = i+2;k<=j-2;k++) if(nums[k] == y) return true;
            }
        return false;
    }
};