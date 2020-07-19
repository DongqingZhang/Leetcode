class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        helper(n, res);
        return res;
    }
    void helper(int n, vector<int>& res){
        if (n < 1){
            res.push_back(0);
            return;
        }
        helper(n - 1, res);
        int len = res.size();
        for (int i = 0;i<len;i++){
            res.push_back(res[len-i-1]+pow(2,n-1));
        }
    }
};