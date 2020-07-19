class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return {1};
        vector<int> res(len, 1);
        for (int i = 0;i<len-1;i++){
            res[i+1] = res[i]*nums[i];
        }
        int tmp = 1;
        for (int i = len - 1;i >= 0;i--){
            res[i] = res[i]*tmp;
            tmp*=nums[i];
        }
        return res;
    }
};