class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> tmp;
        vector<vector<string>> res;
        helper(tmp, res, n);
        return res;
    }
    void helper(vector<int>& tmp, vector<vector<string>>& res, int n){
        if (tmp.size() == n) collectSolu(tmp, res);
        for (int i = 0;i<n;i++){
            if (isValid(tmp,i)){
                tmp.push_back(i);
                helper(tmp, res, n);
                tmp.pop_back();
            }
        }
    }
    bool isValid(vector<int>& tmp, int ind){
        for (int i = 0;i<tmp.size();i++){
            if (tmp[i] == ind||tmp[i]+i==ind+tmp.size()||tmp[i]-i==ind-tmp.size()) return false;
        }
        return true;
    }
    void collectSolu(vector<int>& tmp, vector<vector<string>>& res){
        vector<string> res0(tmp.size(),string(tmp.size(),'.'));
        for (int i = 0;i<tmp.size();i++){
            res0[i][tmp[i]] = 'Q';
        }
        res.push_back(res0);
    }
};