class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m<1)
            return false;
        int n = matrix[0].size();
        if (n<1)
            return false;
        int x = 0;
        int y = m*n-1;
        int temp;
        if (matrix[m-1][n-1] == target||matrix[0][0] == target)
            return true;
        while (y-x>1){
            temp = (x + y)/2;
            if (matrix[temp/n][temp%n] < target){
                x = temp;
            }
            else if (matrix[temp/n][temp%n] > target){
                y = temp;
            }
            else
                return true;
        }
        return false;
    }
};