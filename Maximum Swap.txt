class Solution {
public:
    int maximumSwap(int num) {
        if(num<10) return num;
        vector<int> bits;
        int num0 = num;
        while(num0){
            bits.push_back(num0%10);
            num0/=10;
        }
        int res = generate(bits);
        for(int i = 0;i < bits.size();i++)
            for(int j = 0;j < i;j++){
                int tmp = bits[i];
                bits[i] = bits[j];
                bits[j] = tmp;
                res = max(res,generate(bits));
                tmp = bits[i];
                bits[i] = bits[j];
                bits[j] = tmp;
            }
        return res;
    }
    int generate(vector<int>& bits){
        int res = 0;
        for(int i = bits.size()-1;i >= 0;i--){
            res *= 10;
            res += bits[i];
        }
        return res;
    }
};