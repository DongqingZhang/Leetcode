class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sol;
        if (n<1||k<1||k>n) return res;
        helper(n, 0, k, res, sol);
        return res;
    }
    void helper(int n, int start, int k, vector<vector<int>>& res, vector<int> sol){
        if (sol.size() == k){
            res.push_back(sol);
            return;
        }
        for (int i = start+1;i<=n;i++){
            sol.push_back(i);
            helper(n, i, k, res, sol);
            sol.pop_back();
        }
    }
};