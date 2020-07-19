class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mask(m,vector<int>(n,0));
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                mask[i][j] = -matrix[i][j];
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0;i<m;i++)
                for(int j = 0;j<n;j++){
                    if(mask[i][j] == -1){
                        flag = true;
                        continue;
                    }
                    if(i-1>=0){
                        if(mask[i-1][j] == -1){
                            mask[i-1][j] = mask[i][j]+1;
                        }
                        else if(mask[i-1][j]>mask[i][j]+1){
                            mask[i-1][j] = mask[i][j]+1;
                            flag = true;
                        }
                    }
                    if(i+1<m){
                        if(mask[i+1][j] == -1){
                            mask[i+1][j] = mask[i][j]+1;
                            flag = true;
                        }
                        else if(mask[i+1][j]>mask[i][j]+1){
                            mask[i+1][j] = mask[i][j]+1;
                            flag = true;
                        }
                    }
                    if(j-1>=0){
                        if(mask[i][j-1] == -1){
                            mask[i][j-1] = mask[i][j]+1;
                            flag = true;
                        }
                        else if(mask[i][j-1]>mask[i][j]+1){
                            mask[i][j-1] = mask[i][j]+1;
                            flag = true;
                        }
                    }
                    if(j+1<n){
                        if(mask[i][j+1] == -1){
                            mask[i][j+1] = mask[i][j]+1;
                            flag = true;
                        }
                        else if(mask[i][j+1]>mask[i][j]+1){
                            mask[i][j+1] = mask[i][j]+1;
                            flag = true;
                        }
                    }
                }
        }
        return mask;
    }
};