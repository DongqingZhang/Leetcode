class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x^y;
        int hamm = 0;
        while(res){
            hamm+=res%2;
            res>>=1;
        }
        return hamm;
    }
};