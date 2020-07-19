class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minx = INT_MAX, miny = INT_MAX;
        if(ops.size() == 0) return m*n;
        for(auto a:ops){
            minx = min(minx, a[0]);
            miny = min(miny, a[1]);
        }
        return minx*miny;
    }
};