class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        if(m == 0) return 0;
        int n = picture[0].size();
        vector<int> cntM(m, 0);
        vector<int> cntN(n, 0);
        int res = 0;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(picture[i][j] == 'B'){
                    cntM[i]++;
                    cntN[j]++;
                }
            }
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(cntM[i] == 1 && cntN[j] == 1 && picture[i][j] == 'B') res++;
            }
        return res;
        
    }
};