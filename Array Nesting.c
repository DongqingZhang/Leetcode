class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size(), res = 0;
        vector<bool> flags(len, false);
        for(int i = 0;i<len;i++){
            if(flags[i]) continue;
            int tmp = nums[i];
            int cnt = 1;
            while(nums[tmp]!=nums[i]){
                flags[tmp] = true;
                tmp = nums[tmp];
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};