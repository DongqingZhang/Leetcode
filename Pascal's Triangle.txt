class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows<=0){vector<vector<int>>res; return res;}
        return helper(numRows);
    }
    vector<vector<int>> helper(int n){
        if (n==1){
            vector<vector<int>> res;
            res.push_back({1});
            return res;
        }
        vector<vector<int>> res = helper(n-1);
        res.push_back({});
        res[n-1].push_back(1);
        for (int i=1;i<n-1;i++){
            res[n-1].push_back(res[n-2][i-1]+res[n-2][i]);
        }
        res[n-1].push_back(1);
        return res;
    }
};