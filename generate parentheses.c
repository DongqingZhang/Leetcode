class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sample;
        helper(res, sample, 0, 0, 0, n);
        return res;
    }
    void helper(vector<string> &res, string &sample, int left, int right, int depth, int n){
        if (depth == 2*n) res.push_back(sample);
        if (left < n){
            sample.push_back('(');
            helper(res, sample, left+1, right, depth+1, n);
            sample.pop_back();
        }
        if (right < left){
            sample.push_back(')');
            helper(res, sample, left, right+1, depth+1, n);
            sample.pop_back();
        }
    }
};