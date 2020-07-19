class Solution {
public:
    string multiply(string num1, string num2) {
        if (!num1.length()||!num2.length()||num1[0] == '0'||num2[0] == '0'){
            string res(1,'0');
            return res;
        }
        string res(num1.length()+num2.length()+1,'0');
        std::reverse(num1.begin(),num1.end());
        std::reverse(num2.begin(),num2.end());
        int prod;
        int exist;
        for (int i = 0;i<num1.length();i++){
            int carry = 0;
            for (int j = 0;j<num2.length();j++){
                prod = (num1[i] - '0')*(num2[j] - '0');
                exist = res[i+j] - '0';
                res[i+j] = (prod + carry + exist)%10+'0';
                carry = (prod + carry + exist)/10;
            }
            if (carry!=0)
                res[i+num2.length()] += carry;
        }
        std::reverse(res.begin(),res.end());
        int start = 0;
        while(res[start] == '0' && start<res.size()){
            start++;
        }
        if (start == res.size()) return "0";
        return res.substr(start,res.size()-start);
    }
};