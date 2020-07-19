class Solution {
public:
    int findComplement(int num) {
        int bit = 1, num0 = num;
        while(num0 = (num0>>1)){
            bit++;
        }
        return pow(2,bit) - num - 1;
    }
};