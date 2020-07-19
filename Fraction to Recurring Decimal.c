class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if((numerator<0&&denominator>0)||(numerator>0&&denominator<0)) res.push_back('-');
        long numerator1 = abs((long)numerator);
        long denominator1 = abs((long)denominator);
        vector<long int> partDec;
        long rem = numerator1%denominator1;
        res.append(to_string(numerator1/denominator1));
        if(rem==0) return res;
        res.push_back('.');
        int i,offset = res.size();
        bool flag = false;
        partDec.push_back(rem);
        while(1){
            rem*=10;
            res.append(to_string(rem/denominator1));
            rem = rem%denominator1;
            if (rem==0) break;
            for(i=0;i<partDec.size();i++){
                if(partDec[i]==rem){
                    flag = true;
                    break;
                }
            }
            partDec.push_back(rem);
            if(flag) break;
        }
        if(flag){
            res.push_back(')');
            res.insert(res.begin()+i+offset,'(');
        }
        return res;
    }
};