class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        for (int i=1;i<=rowIndex;i++){
            res.push_back((int)((double)res[i-1]*(rowIndex-i+1)/i));
        }
        return res;
    }
};