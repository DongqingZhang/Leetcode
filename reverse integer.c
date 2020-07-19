class Solution {
public:
    int reverse(int x) {
        int flag = 0;
        if (x<0){
            x = -x;
            flag = 1;
        }
        int r = 0;
        while(x) {
            if (r > (INT_MAX-x%10)/10) return 0;
            r = r*10 + x%10;
            x /= 10;
        }
        if (flag == 1) r = -r;
        return r;
    }
};