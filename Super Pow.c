class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 1) return powmod(a,b[0]);
        int tmp = powmod(a,b[b.size()-1]);
        b.pop_back();
        return (powmod(superPow(a,b),10)*tmp)%1337;
    }
    int powmod(int a, int k){
        int res = 1;
        a%=1337;
        for(int i = 0;i<k;i++){
            res=(res*a)%1337;
        }
        return res;
    }
};