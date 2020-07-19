class Solution {
public:
    int rob(vector<int>& nums) {
        int money1=0,money2=0;
        for(auto a:nums){
            int moneytmp1 = max(money2,money1);
            money2 = money1+a;
            money1 = moneytmp1;
        }
        return max(money1,money2);
    }
};