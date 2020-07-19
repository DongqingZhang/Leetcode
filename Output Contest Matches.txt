class Solution {
public:
    string findContestMatch(int n) {
        vector<int> res;
        helper(res, n);
        int len = res.size()-1;
        return generateStr(res, 0, len);
    }
    void helper(vector<int>& res, int n){
        if(n == 2){
            res.push_back(1);
            res.push_back(2);
            return;
        }
        vector<int> res1;
        helper(res1, n/2);
        for(int i = 0;i<n/2;i++){
            res.push_back(res1[i]);
            res.push_back(n+1-res1[i]);
        }
    }
    string generateStr(vector<int>& res, int i, int j){
        if(j-i==1) return "("+to_string(res[i])+","+to_string(res[i+1])+")";
        string str;
        string str1 = generateStr(res, i, i+(j-i)/2);
        string str2 = generateStr(res, i+(j-i)/2+1, j);
        str = "("+str1+","+str2+")";
        return str;
    }
};