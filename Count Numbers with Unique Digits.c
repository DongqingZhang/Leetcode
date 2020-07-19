class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10) n = 10;
        if (n == 0) return 1;
        if (n == 1) return 10;
        if (n == 2) return 91;
        vector<int> f(n+1,0);
        f[0] = 1;
        f[1] = 9;
        f[2] = 81;
        for (int i = 3;i <= n;i++)
            f[i] = f[i - 1]*(9-i+2);
        int res = 0;
        for (int i = 0;i <= n;i++)
            res += f[i];
        return res;
    }
};