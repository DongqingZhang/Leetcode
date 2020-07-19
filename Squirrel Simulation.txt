class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int len = nuts.size(), res = INT_MAX, dist = 0;
        int ai, bi;
        for(int i = 0;i < len;i++){
            ai = abs(tree[0]-nuts[i][0])+abs(tree[1]-nuts[i][1]);
            bi = abs(squirrel[0]-nuts[i][0])+abs(squirrel[1]-nuts[i][1]);
            res = min(res, bi-ai);
            dist += 2*ai;
        }
        return dist+res;
    }
};