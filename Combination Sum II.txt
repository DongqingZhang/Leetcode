class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        if (candidates.size() == 0) return res;
        sort(candidates.begin(),candidates.end());
        helper(candidates, target, res, tmp, -1);
        return res;
    }
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& tmp, int start){
        if (target > 0){
            for (int i = start+1;i<candidates.size()&&candidates[i] <= target;i++){
                if (i>start+1&&candidates[i] == candidates[i-1]) continue;
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