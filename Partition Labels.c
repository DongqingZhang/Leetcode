class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.length();
        vector<int> lastInd(26,0);
        for(int i = 0;i<S.length();i++) lastInd[S[i]-'a'] = i;
        vector<int> res;
        int start = 0, end = 0;
        for(int i = 0;i<S.length();i++){
            end = max(end,lastInd[S[i]-'a']);
            if(end == i){
                res.push_back(end-start+1);
                start = end+1;
            }
        }
        return res;
    }
};