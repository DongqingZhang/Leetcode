class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    int len = nums.size();
    vector<int> res(len,0);
    int i = 0, j = len-1;
    int ind = a>0?len-1:0;
    while (i<=j){
        if (a>0) res[ind--] = quad(a,b,c,nums[i])<quad(a,b,c,nums[j])?quad(a,b,c,nums[j--]):quad(a,b,c,nums[i++]);
        if (a<=0) res[ind++] = quad(a,b,c,nums[i])<quad(a,b,c,nums[j])?quad(a,b,c,nums[i++]):quad(a,b,c,nums[j--]);
    }
    return res;
    }
    int quad(int a,int b, int c, int val){
        return a*val*val+b*val+c;
    }
};