class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        if (candidates.size() == 0) return res;
        sort(candidates.begin(),candidates.end());
        helper(candidates, target, res, tmp, 0);
        return res;
    }
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& tmp, int start){
        if (target > 0){
            for (int i = start;i<candidates.size()&&candidates[i] <= target;i++){
                tmp.push_back(candidates[i]);
                helper(candidates, target - candidates[i], res, tmp, i);
                tmp.erase(tmp.begin()+tmp.size()-1);
            }
        }
        else if(target == 0){
            res.push_back(tmp);
        }
    }
};