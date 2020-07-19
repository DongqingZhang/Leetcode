class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN), sell(0), pre_buy(INT_MIN), pre_sell(0), pp_sell(0);
        for(auto price:prices){
            buy = max(pp_sell - price, pre_buy);
            sell = max(pre_buy + price, pre_sell);
            pre_buy = buy;
            pp_sell = pre_sell;
            pre_sell = sell;
        }
        return sell;
    }
};