class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left;i <= right;i++){
            if(selfDivide(i)) res.push_back(i);
        }
        return res;
    }
    bool selfDivide(int num){
        int num0 = num;
        while(num0){
            int val = num0%10;
            num0/=10;
            if(val == 0 || num%val !=0) return false;
        }
        return true;
    }
};