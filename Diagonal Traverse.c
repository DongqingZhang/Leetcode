class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size(), direct = 1, x = 0, y = 0;
        for(int i = 0;i<m*n;i++){
            res.push_back(matrix[x][y]);
            x-=direct;
            y+=direct;
            if(x==m){x=m-1; y+=2;direct*=(-1);}
            if(y==n){y=n-1; x+=2;direct*=(-1);}
            if(x<0){x=0;direct*=(-1);}
            if(y<0){y=0;direct*=(-1);}
        }
        return res;
    }
};