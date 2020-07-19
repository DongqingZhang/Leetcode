class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price, special, needs);
    }
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        int c = directP(needs, price);
        for(auto a:special){
            bool flag = true;
            vector<int> tmp(a.size()-1,0);
            for(int i = 0;i<a.size()-1;i++){
                if(needs[i] < a[i]){
                    flag = false;
                    break;
                }
                tmp[i] = needs[i] - a[i];
            }
            if(flag) c = min(c,a[a.size()-1]+helper(price, special, tmp));
        }
        return c;
    }
    int directP(vector<int>& price, vector<int>& needs){
        int c = 0;
        for(int i = 0;i<needs.size();i++) c+=needs[i]*price[i];
        return c;
    }
};