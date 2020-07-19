class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(helper(nums,0,nums.size()-2),helper(nums,1,nums.size()-1));
    }
    int helper(vector<int>& nums, int s, int e) {
        int money1=0,money2=0;
        for(int i=s;i<=e;i++){
            int a = nums[i];
            int moneytmp1 = max(money2,money1);
            money2 = money1+a;
            money1 = moneytmp1;
        }
        return max(money1,money2);
    }
};