class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path(1,0);
        int N = graph.size();
        helper(N, 0, path, graph, res);
        return res;
    }
    void helper(int N, int node, vector<int>& path, vector<vector<int>>& graph, vector<vector<int>>& res){
        if(node == N-1) res.push_back(path);
        for(auto a:graph[node]){
            path.push_back(a);
            helper(N, a, path, graph, res);
            path.pop_back();
        }
    }
};