class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k*k;
        int num1 = k, num2 = k*(k-1), prevnum1;
        for (int i = 3;i <= n;i++){
            prevnum1 = num1;
            num1 = num2;
            num2 = (prevnum1+num2)*(k-1);
        }
        return num1+num2;
    }
};