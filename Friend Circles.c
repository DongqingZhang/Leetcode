class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size(), res = 0;
        vector<bool> visited(m,false);
        for(int i = 0;i<m;i++){
            if(visited[i]) continue;
            dfs(M, visited, i);
            res++;
        }
        return res;
    }
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i){
        visited[i] = true;
        for(int j = 0;j < M.size();j++){
            if(M[i][j] && !visited[j]) dfs(M, visited, j);
        }
    }
};