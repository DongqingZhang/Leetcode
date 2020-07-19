class Solution {
public:
    double myPow(double x, int n) {
        if (n==-2147483648)
            return 1.0/(myPow(x,-n-1)*x);
        if (n<0)
            return 1.0/myPow(x,-n);
        vector <int> bits;
        while(n){
            bits.push_back(n&1);
            n = n>>1;
        }
        double base = x;
        double res = 1;
        for (auto iter = bits.begin();iter!=bits.end();iter++){
            if (*iter)  res *= base;
            base *= base;
        }
        return res;
    }
};