class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size()==0||rooms[0].size()==0) return;
        int MAX = 2147483647;
        queue<int> q;
        int m=rooms.size();
        int n=rooms[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0) q.push(i*n+j);
            }
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            int r = tmp/n, c = tmp%n;
            for (int i=-1;i<2;i++)
                for (int j=-1;j<2;j++){
                    if ((i==0||j==0)&&!(i==0&&j==0)&&isValid(i+r,j+c,m,n)&&rooms[i+r][j+c]==MAX){
                        rooms[i+r][j+c] = rooms[r][c]+1;
                        q.push((i+r)*n+j+c);
                    }
                }
        }
    }
    bool isValid(int i, int j, int m, int n){
        return i>=0&&j>=0&&i<m&&j<n;
    }
};