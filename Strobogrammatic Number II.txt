class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        helper(res, n, n);
        return res;
    }
    void helper(vector<string>& res, int n, int max){
        if (n==0){res.push_back("");return;}
        if (n==1){
            res.push_back("1");
            res.push_back("0");
            res.push_back("8");
            return;
        }
        helper(res, n-2, max);
        int len = res[0].size();
        int sz = res.size();
        for (int i=0;i<sz;i++) res.push_back('6'+res[i]+'9');
        for (int i=0;i<sz;i++) res.push_back('9'+res[i]+'6');
        for (int i=0;i<sz;i++) res.push_back('8'+res[i]+'8');
        if (n != max){
            for (int i=0;i<sz;i++) res.push_back('0'+res[i]+'0');
        }
        for (int i=0;i<sz;i++) res[i] = '1'+res[i]+'1';
    }
};