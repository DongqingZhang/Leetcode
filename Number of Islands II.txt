class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> roots(m*n,-1);
        vector<int> res;
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int cnt = 0;
        for(int i = 0;i<positions.size();i++){
            int root = positions[i].first*n+positions[i].second;
            roots[root] = root;
            cnt++;
            for(auto a:dirs){
                pair<int,int> tmp;
                tmp.first = positions[i].first+a.first;
                tmp.second = positions[i].second+a.second;
                if(tmp.first<0||tmp.first==m||tmp.second<0||tmp.second==n||roots[tmp.first*n+tmp.second]==-1) continue;
                int rootnb = findIsland(roots, tmp.first*n+tmp.second);
                if(rootnb!=root){
                    cnt--;
                    roots[root] = rootnb;
                    root = rootnb;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int findIsland(vector<int>& roots, int root){
        return root==roots[root]?root:findIsland(roots,roots[root]);
    }
};