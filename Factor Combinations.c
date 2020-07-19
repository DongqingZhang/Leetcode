class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(n, tmp, res, 2);
        res.pop_back();
        return res;
    }
    void helper(int n, vector<int>& tmp, vector<vector<int>>& res, int curN){
        if (n==1){
            res.push_back(tmp);
            return;
        }
        int upper = (int)sqrt((double)n);
        for(int i=curN;i<=n;i++){
            if((i<=upper&&n%i==0)||i==n){
                tmp.push_back(i);
                helper(n/i,tmp,res,i);
                tmp.pop_back();
            }
        }
    }
};