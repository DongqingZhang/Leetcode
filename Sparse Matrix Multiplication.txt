class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ma=A.size(), na=A[0].size();
        int mb=B.size(), nb=B[0].size();
        vector<vector<int>> C(ma,vector<int>(nb,0));
        for (int i=0;i<ma;i++){
            for (int k=0;k<mb;k++){
                if (A[i][k]){
                    for (int j=0;j<nb;j++)
                        if (B[k][j])
                            C[i][j] +=A[i][k]*B[k][j];
                }
            }
        }
        return C;
    }
};