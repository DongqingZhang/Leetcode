class Solution {
public:
    int countDigitOne(int n) {
        long res = 0;
        int a,b;
        for (long i = 1;i<=n;i*=10){
            a = n/i;
            b = n%i;
            if (a%10>1) res += (a/10+1)*i;
            if (a%10==1) res += (a/10)*i+b+1;
            if (a%10==0) res += (a/10)*i;
        }
        return res;
    }
};