class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 10) return a;
        vector<int> res;
        for(int i = 9;i > 1;i--){
            while(a!=1 && a%i==0){
                res.push_back(i);
                a/=i;
            }
        }
        if(a!=1) return 0;
        long result = 0;
        int len = res.size()-1;
        for(int i = len;i>=0;i--){
            result *= 10;
            result += res[i];
            if(result > INT_MAX) return 0;
        }
        return result;
    }
};