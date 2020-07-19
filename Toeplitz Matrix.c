class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        for(int i = 1-m;i<=n-1;i++){
            if(i < 0){
                int val = matrix[-i][0];
                for(int j = 0;j<min(m+i,n);j++) if(matrix[j-i][j]!=val) return false;
            }
            if(i >= 0){
                int val = matrix[0][i];
                for(int j = 0;j<min(m,n-i);j++) if(matrix[j][j+i]!=val) return false;
            }
        }
        return true;
    }
};