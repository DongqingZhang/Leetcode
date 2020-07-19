class Solution {
public:
    int findNthDigit(int n) {
        int digit = 0;
        long digCnt = 0;
        while(n>digCnt){
            digit++;
            digCnt += 9*pow(10,digit-1)*digit;
        }
        digCnt -= 9*pow(10,digit-1)*digit;
        int num = pow(10,digit-1)+(n-1-digCnt)/digit;
        int cnt = digit - (n-1-digCnt)%digit;
        int res = num/pow(10,cnt-1);
        res%=10;
        return res;
    }
};