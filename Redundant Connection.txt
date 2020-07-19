class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(2001,0), res = {0,0};
        for(int i = 0;i < 2001;i++) parents[i] = i;
        for(auto edge:edges){
            int a = edge[0], b = edge[1];
            int pa = find(parents,a), pb = find(parents,b);
            if(pa == pb){res = edge;}
            parents[pa] = pb;
        }
        return res;
    }
    int find(vector<int>& parents, int a){
        while(parents[a] != a) a = parents[a];
        return a;
    }
};