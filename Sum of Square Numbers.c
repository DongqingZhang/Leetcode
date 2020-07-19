class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);
        while(r>=l){
            int cur = l*l+r*r;
            if(cur<c) l++;
            else if(cur>c) r--;
            else return true;
        }
        return false;
    }
};