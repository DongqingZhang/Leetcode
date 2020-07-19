class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int l1 = num1.length();
        int l2 = num2.length();
        string res;
        int carry = 0;
        if(l1 < l2){
            for(int i = 0;i<l2-l1;i++) num1.push_back('0');
        }
        else{
            for(int i = 0;i<l1-l2;i++) num2.push_back('0');
        }
        for(int i = 0;i<max(l1,l2);i++){
            res.push_back((num1[i]-'0'+num2[i]-'0'+carry)%10+'0');
            carry = (num1[i]-'0'+num2[i]-'0'+carry)/10;
        }
        if(carry) res.push_back(carry+'0');
        reverse(res.begin(),res.end());
        return res;
    }
};