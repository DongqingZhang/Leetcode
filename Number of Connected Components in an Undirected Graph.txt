class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n,0);
        for (int i=0;i<n;i++) roots[i] = i;
        for (auto a:edges){
            int e1 = find(roots, a.first);
            int e2 = find(roots, a.second);
            if (e1!=e2){
                roots[e2]=e1;
                n--;
            }
        }
        return n;
    }
    int find(vector<int>& roots, int id){
        while(roots[id]!=id){
            roots[id] = roots[roots[id]];
            id = roots[roots[id]];
        }
        return id;
    }
};