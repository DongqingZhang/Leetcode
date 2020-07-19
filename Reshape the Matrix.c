class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if(m*n!=r*c) return nums;
        vector<vector<int>> res(r,vector<int>(c,0));
        int cnt = 0;
        for(int cnt = 0;cnt<m*n;cnt++){
                res[cnt/c][cnt%c] = nums[cnt/n][cnt%n];
        }
        return res;
    }
};