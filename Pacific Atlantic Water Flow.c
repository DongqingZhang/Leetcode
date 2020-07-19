class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        if(n == 0) return res;
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        queue<pair<int,int>> pacq;
        queue<pair<int,int>> atlq;
        for(int i = 0;i < m;i++){pacq.push({i,0});pac[i][0] = true;}
        for(int i = 1;i < n;i++){pacq.push({0,i});pac[0][i] = true;}
        for(int i = 0;i < m;i++){atlq.push({i,n-1});atl[i][n-1] = true;}
        for(int i = 0;i < n-1;i++){atlq.push({m-1,i});atl[m-1][i] = true;}
        while(!pacq.empty()){
            pair<int,int> tmp = pacq.front();
            pacq.pop();
            if(tmp.first+1 < m && pac[tmp.first+1][tmp.second] == false && matrix[tmp.first+1][tmp.second]>=matrix[tmp.first][tmp.second]){
                pacq.push({tmp.first+1,tmp.second});
                pac[tmp.first+1][tmp.second] = true;
            }
            if(tmp.first-1 >= 0 && pac[tmp.first-1][tmp.second] == false && matrix[tmp.first-1][tmp.second]>=matrix[tmp.first][tmp.second]){
                pacq.push({tmp.first-1,tmp.second});
                pac[tmp.first-1][tmp.second] = true;
            }
            if(tmp.second+1 < n && pac[tmp.first][tmp.second+1] == false && matrix[tmp.first][tmp.second+1]>=matrix[tmp.first][tmp.second]){
                pacq.push({tmp.first,tmp.second+1});
                pac[tmp.first][tmp.second+1] = true;
            }
            if(tmp.second-1 >=0 && pac[tmp.first][tmp.second-1] == false && matrix[tmp.first][tmp.second-1]>=matrix[tmp.first][tmp.second]){
                pacq.push({tmp.first,tmp.second-1});
                pac[tmp.first][tmp.second-1] = true;
            }
        }
        while(!atlq.empty()){
            pair<int,int> tmp = atlq.front();
            atlq.pop();
            if(tmp.first+1 < m && atl[tmp.first+1][tmp.second] == false && matrix[tmp.first+1][tmp.second]>=matrix[tmp.first][tmp.second]){
                atlq.push({tmp.first+1,tmp.second});
                atl[tmp.first+1][tmp.second] = true;
            }
            if(tmp.first-1 >= 0 && atl[tmp.first-1][tmp.second] == false && matrix[tmp.first-1][tmp.second]>=matrix[tmp.first][tmp.second]){
                atlq.push({tmp.first-1,tmp.second});
                atl[tmp.first-1][tmp.second] = true;
            }
            if(tmp.second+1 < n && atl[tmp.first][tmp.second+1] == false && matrix[tmp.first][tmp.second+1]>=matrix[tmp.first][tmp.second]){
                atlq.push({tmp.first,tmp.second+1});
                atl[tmp.first][tmp.second+1] = true;
            }
            if(tmp.second-1 >=0 && atl[tmp.first][tmp.second-1] == false && matrix[tmp.first][tmp.second-1]>=matrix[tmp.first][tmp.second]){
                atlq.push({tmp.first,tmp.second-1});
                atl[tmp.first][tmp.second-1] = true;
            }
        }
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        return res;
    }
};