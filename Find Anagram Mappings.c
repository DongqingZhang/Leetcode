class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int m = A.size();
        vector<int> res(m,0);
        unordered_map<int,int> map;
        for(int i = 0;i<m;i++) map[B[i]] = i;
        for(int i = 0;i<m;i++) res[i] = map[A[i]];
        return res;
    }
};