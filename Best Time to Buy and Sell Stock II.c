class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int maxProf = 0;
        for (int i = 1; i < prices.size();i++){
            maxProf += prices[i] - prices[i-1]>0?prices[i] - prices[i-1]:0;
        }
        return maxProf;
    }
};