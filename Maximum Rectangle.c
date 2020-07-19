class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        vector<int> left(n,0), right(n,n-1), heights(n,0);
        int res = 0;
        for(int i = 0;i<m;i++){
            int lefttmp = 0, righttmp = n-1;
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1'){
                    heights[j]+=1;
                    left[j]=max(left[j],lefttmp);
                }
                else{
                    heights[j] = 0;
                    lefttmp = j+1;
                    left[j] = 0;
                }
            }
            for(int j = n-1;j>=0;j--){
                if(matrix[i][j] == '1') right[j]=min(right[j],righttmp);
                else{righttmp = j-1;right[j] = n-1;}
            }
            for(int j = 0;j<n;j++) res = max(res,(right[j]-left[j]+1)*heights[j]);
        }
        return res;
    }
};