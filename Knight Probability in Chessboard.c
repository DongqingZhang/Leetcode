class Solution {
public:
    vector<pair<int,int>> disps={{-2,-1},{-1,-2},{2,1},{1,2},{-2,1},{-1,2},{2,-1},{1,-2}};
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> visited(K+1,vector<vector<double>>(N,vector<double>(N,-1.0)));
        return helper(N, K, r, c, visited, disps);
    }
    double helper(int N, int K, int r, int c, vector<vector<vector<double>>>& visited,vector<pair<int,int>>& disps){
        if(visited[K][r][c] >= 0.0) return visited[K][r][c];
        if(K == 0){
            visited[0][r][c] = 1.0;
            return 1.0;
        }
        vector<double> p(8,0.0);
        int a, b;
        for(int i = 0;i < 8;i++){
            a = r+disps[i].first;
            b = c+disps[i].second;
            if(a<0 || b<0 || a>N-1 || b>N-1) continue;
            p[i] = visited[K-1][a][b] >= 0.0?visited[K-1][a][b]:helper(N, K-1, a, b,visited,disps);
        }
        double res = 0;
        for(auto a:p) res+=a/8;
        visited[K][r][c] = res;
        return res;
    }
};