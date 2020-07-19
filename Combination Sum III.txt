class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(k, n, tmp, res, 0);
        return res;
    }
    void helper(int k, int n, vector<int>& tmp, vector<vector<int>>& res, int maxN){
        if (k == 0) return;
        int sum = accumulate(tmp.begin(),tmp.end(),0);
        for (int i = maxN+1;i < 10;i++){
            if (i > n-sum) break;
            if (k == 1){
                if (i == n-sum){
                    tmp.push_back(i);
                    res.push_back(tmp);
                    tmp.pop_back();
                    return;
                }
            }
            tmp.push_back(i);
            cout<<i<<endl;
            helper(k-1, n, tmp, res, i);
            tmp.pop_back();
        }
    }
};