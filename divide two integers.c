class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        int res = 0, s;
        if (dividend == INT_MIN){
            if (divisor>0){
                res = 1;
                dividend += divisor;
                dividend = -dividend;
            }
            else{
                res = 1;
                dividend -= divisor;
                dividend = -dividend;
            }
        }
        else if(dividend<0&&divisor<0){
            s = 1;
            dividend = -dividend;
            divisor = -divisor;
        }
        else if(dividend<0&&divisor>0){
            s = -1;
            dividend = -dividend;
        }
        else if(dividend>0&&divisor<0){
            s = -1;
            divisor = -divisor;
        }
        else s = 1;
        if (dividend < divisor) return 0;
        int tmp = divisor;
        int count = 0;
        while(tmp <= dividend/2){
            tmp<<1;
            count++;
        }
        while(count>=0){
            if (dividend > tmp){
                dividend -= tmp;
                res<<1;
                res += 1;
            }
            else
                res<<1;
            tmp>>1;
            count--;
        }
        return res;
    }
};