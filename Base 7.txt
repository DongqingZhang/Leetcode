class Solution {
public:
    string convertToBase7(int num) {
        string res;
        long num0 = num;
        if(num0<0) num0 = -num0;
        do{
            res.push_back(num0%7+'0');
            num0/=7;
        }while(num0);
        if(num < 0) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};